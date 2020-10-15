import java.util.*;
import java.io.*;

public class ColoringHamerlyFast {
    public static void main(String args[]) throws Exception {
        BufferedReader s = new BufferedReader(new InputStreamReader(System.in));

        String tokens[] = s.readLine().split(" ");
        int n = Integer.parseInt(tokens[0]), m = Integer.parseInt(tokens[1]);

        int edges_u[] = new int[m];
        int edges_v[] = new int[m];
        int dist[] = new int[n];
        final int oo = 1000000;
        Arrays.fill(dist, oo);

        int num_edges[] = new int[n];

        for (int i = 0; i < m; ++i) {
            tokens = s.readLine().split(" ");
            edges_u[i] = Integer.parseInt(tokens[0]) - 1;
            edges_v[i] = Integer.parseInt(tokens[1]) - 1;
            num_edges[edges_u[i]]++;
            num_edges[edges_v[i]]++;
        }

        int edges[][] = new int[n][];
        for (int i = 0; i < n; ++i) {
            edges[i] = new int[num_edges[i]];
        }

        for (int i = 0; i < m; ++i) {
            int u = edges_u[i], v = edges_v[i];
            num_edges[u]--;
            num_edges[v]--;
            edges[u][num_edges[u]] = v;
            edges[v][num_edges[v]] = u;
        }

        int queue[] = new int[n];
        int length = 0;
        int front = 0;
        queue[front] = 0;
        length++;
        dist[0] = 0;
        while (0 < length) {
            length--;
            int current = queue[front];
            front = (front + 1) % n;
            int d = dist[current];
            for (int e : edges[current]) {
                if (d + 1 < dist[e]) {
                    queue[(front + length) % n] = e;
                    length++;
                    dist[e] = d + 1;
                }
            }
        }

        System.out.println(dist[n-1] - 1);
    }
}
