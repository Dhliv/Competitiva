import java.util.*;
import java.io.*;

public class Arknave {
    static int[] tax;
    static int[] sz;
    static long[] depth;
    static long[] sumTax;
    static long[] ans;
    static List<Edge>[] tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        tax = new int[n];
        tree = new List[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            tax[i] = Integer.parseInt(st.nextToken());
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());

            tree[u].add(new Edge(v, w));
            tree[v].add(new Edge(u, w));
        }

        depth = new long[n];
        sz = new int[n];
        sumTax = new long[n];
        dfs(0, -1);

        long sumDist = 0;
        long sumTaxDist = 0;

        for (int i = 0; i < n; i++) {
            sumDist += depth[i];
            sumTaxDist += tax[i] * depth[i];
        }

        ans = new long[n];
        solve(0, -1, sumDist, sumTaxDist);

        for (int i = 0; i < n; i++) {
            pw.println(ans[i]);
        }
        pw.close();
    }

    public static void dfs(int u, int p) {
        sz[u] = 1;
        sumTax[u] = tax[u];
        for (Edge e : tree[u]) {
            int v = e.dest;
            int w = e.cost;

            if (v == p) {
                continue;
            }

            depth[v] = depth[u] + w;
            dfs(v, u);
            sumTax[u] += sumTax[v];
            sz[u] += sz[v];
        }
    }

    public static void solve(int u, int p, long sumDist, long sumTaxDist) {
        ans[u] = sumTaxDist + tax[u] * sumDist;
        for (Edge e : tree[u]) {
            int v = e.dest;
            int w = e.cost;

            if (v == p) continue;

            long newSumDist = sumDist - w * sz[v] + w * (sz[0] - sz[v]);
            long newSumTaxDist = sumTaxDist - w * sumTax[v] + w * (sumTax[0] - sumTax[v]);

            solve(v, u, newSumDist, newSumTaxDist);
        }
    }

    private static class Edge {
        int dest, cost;
        Edge(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }
    }
}
