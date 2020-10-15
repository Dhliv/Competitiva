import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class computer_cache_lewin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ComputerCache solver = new ComputerCache();
        solver.solve(1, in, out);
        out.close();
    }

    static class ComputerCache {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            int[] start = new int[m], ls = new int[m];
            PersistentBIT bs = new PersistentBIT(1000010);
            int tot = 0;
            for (int i = 0; i < m; i++) {
                ls[i] = in.nextInt();
                start[i] = tot;
                int[] arr = in.readIntArray(ls[i]);
                for (int j = 0; j < ls[i]; j++) {
                    bs.update(j + start[i], arr[j]);
                    bs.update(j + start[i] + 1, -arr[j]);
                }
                tot += ls[i];
            }
            bs.now++;
            SegmentTreeFast fs = new SegmentTreeFast(n + 10);
            int[] qpos = new int[q+10], qidx = new int[q+10];
            for (int qq = 1; qq <= q; qq++) {
                int type = in.nextInt();
                if (type == 1) {
                    int idx = in.nextInt() - 1, pos = in.nextInt() - 1;
                    fs.modify(pos, pos + ls[idx] - 1, qq);
                    qpos[qq] = pos;
                    qidx[qq] = idx;
                } else if (type == 2) {
                    int pos = in.nextInt() - 1;
                    int query = fs.query(pos, pos);
                    int qp = qpos[query];
                    int qi = qidx[query];
                    if (query == 0) out.println(0);
                    else out.println(bs.query(query, (pos - qp) + start[qi]) % 256);
                } else {
                    int idx = in.nextInt() - 1, l = in.nextInt() - 1, r = in.nextInt() - 1;
                    bs.update(start[idx] + l, +1);
                    bs.update(start[idx] + r + 1, -1);
                }
                bs.now++;
            }
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class SegmentTreeFast {
        int[] value;
        int[] delta;

        public SegmentTreeFast(int n) {
            value = new int[2 * n];
            for (int i = 0; i < n; i++) {
                value[i + n] = getInitValue();
            }
            for (int i = 2 * n - 1; i > 1; i -= 2) {
                value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
            }
            delta = new int[2 * n];
            Arrays.fill(delta, getNeutralDelta());
        }

        int modifyOperation(int x, int y) {
            return Math.max(x, y);
        }

        int queryOperation(int leftValue, int rightValue) {
            return Math.max(leftValue, rightValue);
        }

        int deltaEffectOnSegment(int delta, int segmentLength) {
            if (delta == getNeutralDelta()) return getNeutralDelta();
            // Here you must write a fast equivalent of following slow code:
            // int result = delta;
            // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
            // return result;
            return delta;
//        return delta * segmentLength;
        }

        int getNeutralDelta() {
            return 0;
        }

        int getInitValue() {
            return 0;
        }

        int joinValueWithDelta(int value, int delta) {
            if (delta == getNeutralDelta()) return value;
            return modifyOperation(value, delta);
        }

        int joinDeltas(int delta1, int delta2) {
            if (delta1 == getNeutralDelta()) return delta2;
            if (delta2 == getNeutralDelta()) return delta1;
            return modifyOperation(delta1, delta2);
        }

        void pushDelta(int i) {
            int d = 0;
            for (; (i >> d) > 0; d++) {
            }
            for (d -= 2; d >= 0; d--) {
                int x = i >> d;
                value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
                delta[x] = joinDeltas(delta[x], delta[x >> 1]);
                delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
                delta[x >> 1] = getNeutralDelta();
            }
        }

        int joinNodeValueWithDelta(int i, int len) {
            return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
        }

        public int query(int from, int to) {
            to = Math.min(to, value.length / 2 - 1);
            from = Math.max(from, 0);
            if (to < from) return getInitValue();
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            int res = 0;
            boolean found = false;
            for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
                if ((from & 1) != 0) {
                    res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
                    found = true;
                }
                if ((to & 1) == 0) {
                    res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
                    found = true;
                }
            }
            if (!found) throw new RuntimeException();
            return res;
        }

        public void modify(int from, int to, int delta) {
            if (from > to) return;
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            int a = from;
            int b = to;
            for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
                if ((from & 1) != 0) {
                    this.delta[from] = joinDeltas(this.delta[from], delta);
                }
                if ((to & 1) == 0) {
                    this.delta[to] = joinDeltas(this.delta[to], delta);
                }
            }
            for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
                value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
            }
            for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
                value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class PersistentBIT {
        public int n;
        public int now;
        List<PersistentBIT.Item>[] tree;

        public PersistentBIT(int n) {
            this.n = n;
            tree = LUtils.genArrayList(n + 3);
            for (int i = 0; i < n; i++) {
                tree[i].add(new PersistentBIT.Item(0, 0));
            }
            this.now = 0;
        }

        public void update(int pos, int val) {
            pos += 2;
            for (int i = pos; i < n; i += (i & -i)) {
                PersistentBIT.Item it = tree[i].get(tree[i].size() - 1);
                if (it.id == now) it.data += val;
                else tree[i].add(new PersistentBIT.Item(it.data + val, now));
            }
        }

        public int query(int timestep, int K) {
            K += 2;
            int sum = 0;
            for (int i = K; i > 0; i -= (i & -i)) {
                int idx = Collections.binarySearch(tree[i], new PersistentBIT.Item(0, timestep));
                if (idx < 0) idx = -idx - 2;
                sum += tree[i].get(idx).data;
            }
            return sum;
        }

        static class Item implements Comparable<PersistentBIT.Item> {
            public int data;
            public int id;

            public Item(int data, int id) {
                this.data = data;
                this.id = id;
            }

            public int compareTo(PersistentBIT.Item other) {
                return id - other.id;
            }

        }

    }
}

