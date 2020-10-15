import java.io.*;
import java.util.*;

public class ErrorCorrection_Arknave_Slow {
    private static class SlowFlow {
        static final int INF = (int)1e9;
        int n;
        int[][] graph;
        boolean[] visited;

        SlowFlow(int n) {
            this.n = n;
            graph = new int[n][n];
            visited = new boolean[n];
        }

        void addEdge(int u, int v, int cap) {
            graph[u][v] += cap;
        }

        int dfs(int u, int sink, int flow) {
            if (u == sink) {
                return flow;
            }

            visited[u] = true;
            for (int v = 0; v < n; v++) {
                if (graph[u][v] > 0 && !visited[v]) {
                    int reach = dfs(v, sink, Math.min(flow, graph[u][v]));
                    if (reach > 0) {
                        graph[u][v] -= reach;
                        graph[v][u] += reach;
                        return reach;
                    }
                }
            }

            return 0;
        }

        int flow(int src, int sink) {
            int ans = 0;
            while (true) {
                Arrays.fill(visited, false);
                int aug = dfs(src, sink, INF);
                if (aug == 0) {
                    break;
                }

                ans += aug;
            }

            return ans;
        }
    }

    public static int countInversions(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) > s.charAt(j)) {
                    ans++;
                }
            }
        }

        return ans;
    }

    public static int diff(String s, String t) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                ans += 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] words = new String[n];
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            words[i] = br.readLine();
            int parity = countInversions(words[i]) % 2;
            if (parity % 2 == 0) {
                left.add(i);
            } else {
                right.add(i);
            }
        }

        int leftSize = left.size();
        int rightSize = right.size();

        int src = leftSize + rightSize;
        int sink = src + 1;
        SlowFlow flow = new SlowFlow(sink + 1);
        for (int i = 0; i < leftSize; i++) {
            flow.addEdge(src, i, 1);
        }
        for (int i = 0; i < rightSize; i++) {
            flow.addEdge(leftSize + i, sink, 1);
        }

        // I'm not sure if we want this to pass or we want to force hashing.
        // Difference is 2500^2 * 26 vs 26^2 * 5000, pretty substantial
        for (int i = 0; i < leftSize; i++) {
            for (int j = 0; j < rightSize; j++) {
                if (diff(words[left.get(i)], words[right.get(j)]) == 2) {
                    flow.addEdge(i, left.size() + j, 1);
                }
            }
        }

        System.out.println(n - flow.flow(src, sink));
    }
}
