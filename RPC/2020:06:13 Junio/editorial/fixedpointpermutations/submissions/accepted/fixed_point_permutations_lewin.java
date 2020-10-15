import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class fixed_point_permutations_lewin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FixedPointPermutation solver = new FixedPointPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class FixedPointPermutation {
        long INF = (long) (3e18);
        long[][][] dp;

        long count(int positions, int matches, int fixedpoints) {
            if (positions == 0) return fixedpoints == 0 ? 1 : 0;
            if (dp[positions][matches][fixedpoints] != -1) return dp[positions][matches][fixedpoints];

            long res = 0;
            // choose number which matches position
            if (matches > 0 && fixedpoints > 0) res += count(positions - 1, matches - 1, fixedpoints - 1);
            // choose a number which has a match, but doesn't match position
            if (matches > 1) {
                long d = count(positions - 1, matches - 2, fixedpoints);
                if (d < INF / (matches - 1)) d *= matches - 1; else d = INF;
                res += d;
                if (res > INF) res = INF;
            }
            // choose a number which doesn't match
            if (matches < positions) {
                long d = count(positions - 1, Math.max(0, matches - 1), fixedpoints);
                if (d < INF / (positions - matches)) d *= positions - matches; else d = INF;
                res += d;
                if (res > INF) res = INF;
            }
            return dp[positions][matches][fixedpoints] = res;
        }

        long countSuffix(int[] res, int need) {
            // how many ways to complete res
            int n = res.length;
            boolean[] used = new boolean[n];
            int i = 0;
            for (i = 0; i < n; i++) {
                if (res[i] == -1) break;
                if (res[i] == i) need--;
                if (used[res[i]]) return 0;
                used[res[i]] = true;
            }
            if (need < 0) return 0;
            int matches = 0;
            int positions = 0;
            for (; i < n; i++) {
                if (!used[i]) matches++;
                positions++;
            }
            return count(positions, matches, need);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            long k = in.nextLong() - 1;
            dp = new long[n + 1][n + 1][n + 1];
            AUtils.deepFill(dp, -1);
            if (k >= count(n, n, m)) {
                out.println(-1);
                return;
            }
            int[] res = new int[n];
            Arrays.fill(res, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i] = j;
                    long r = countSuffix(res, m);
                    if (k >= r) k -= r;
                    else break;
                }
            }

            for (int i = 0; i < n; i++) res[i]++;
            out.println(res);
        }

    }

    static class AUtils {
        public static void deepFill(long[][][] x, long val) {
            for (long[][] y : x) deepFill(y, val);
        }

        public static void deepFill(long[][] x, long val) {
            for (long[] y : x) deepFill(y, val);
        }

        public static void deepFill(long[] x, long val) {
            Arrays.fill(x, val);
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}

