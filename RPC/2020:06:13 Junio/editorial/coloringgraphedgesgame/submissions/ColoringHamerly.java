import java.util.*;

public class ColoringHamerly {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt(), m = s.nextInt();

        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            edges.add(new ArrayList<Integer>());
        }
        int dist[] = new int[n];
        final int oo = 1000000;
        Arrays.fill(dist, oo);

        for (int i = 0; i < m; ++i) {
            int a = s.nextInt() - 1, b = s.nextInt() - 1;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        Queue<Integer> frontier = new LinkedList<>();
        frontier.add(0);
        dist[0] = 0;
        while (0 < frontier.size()) {
            int current = frontier.remove();
            int d = dist[current];
            for (int e : edges.get(current)) {
                if (d + 1 < dist[e]) {
                    frontier.add(e);
                    dist[e] = d + 1;
                }
            }
        }

        System.out.println(dist[n-1] - 1);
    }
}
