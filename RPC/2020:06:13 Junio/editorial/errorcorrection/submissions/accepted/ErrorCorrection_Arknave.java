import java.io.*;
import java.util.*;

public class ErrorCorrection_Arknave {
    private static class DFSMatch {
        int n, m;
        List<Integer>[] graph;
        int[] rightToLeft;
        boolean[] visited;

        DFSMatch(int n, int m) {
            this.n = n;
            this.m = m;

            graph = new List[n];
            for (int i = 0; i < n; ++i) {
                graph[i] = new ArrayList<>();
            }

            rightToLeft = new int[m];
            Arrays.fill(rightToLeft, -1);

            visited = new boolean[m];
        }

        void addEdge(int u, int v) {
            graph[u].add(v);
        }

        boolean find(int v) {
            if (rightToLeft[v] == -1)
                return true;
            visited[v] = true;
            int u = rightToLeft[v];
            for (int vv : graph[u]) {
                if (!visited[vv] && find(vv)) {
                    rightToLeft[vv] = u;
                    return true;
                }
            }

            return false;
        }

        int findMatching() {
            for (int u = 0; u < n; u++) {
                Arrays.fill(visited, false);
                for (int v : graph[u]) {
                    if (find(v)) {
                        rightToLeft[v] = u;
                        break;
                    }
                }
            }

            int ans = m;
            for (int v = 0; v < m; v++) {
                if (rightToLeft[v] == -1) {
                    ans--;
                }
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

        DFSMatch match = new DFSMatch(leftSize, rightSize);

        // I'm not sure if we want this to pass or we want to force hashing.
        // Difference is 2500^2 * 26 vs 26^2 * 5000, pretty substantial
        for (int i = 0; i < leftSize; i++) {
            for (int j = 0; j < rightSize; j++) {
                if (diff(words[left.get(i)], words[right.get(j)]) == 2) {
                    match.addEdge(i, j);
                }
            }
        }

        System.out.println(n - match.findMatching());
    }
}
