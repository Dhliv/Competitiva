import java.util.*;
import java.io.*;

class Node {
	public String word;
	public Set<Node> neighbors;
	public int color;
	public int score;
	public Node(String word) {
		this.word = word;
		this.neighbors = new HashSet<Node>();
		this.color = 0;
		this.score = 0;
	}
}

public class ErrorCorrection_cal {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			List<Node> nodes = new ArrayList<>();
			for (int i = 0, N = in.nextInt(); i < N; ++i) nodes.add(new Node(in.next()));
			buildGraph(nodes);
			List<List<Node>> subgraphs = buildSubgraphs(nodes);
			for (List<Node> subgraph : subgraphs)
				for (int i = 0; i < subgraph.size(); ++i)
					scoreGraph(subgraph, subgraph.get(i), i*2, i*2 + 1);
			int max = 0;
			for (List<Node> subgraph : subgraphs) {
				int localMax = 0;
				for (Node node : subgraph)
					if (node.score > localMax) localMax = node.score;
				max += localMax;
			}
			System.out.println(max);
		}
	}

	public static List<List<Node>> buildSubgraphs(List<Node> nodes) {
		List<List<Node>> subgraphs = new ArrayList<>();
		int TAGGED = -9;
		for (Node node : nodes) {
			if (node.color == TAGGED) continue;
			node.color = TAGGED;
			Queue<Node> queue = new LinkedList<>(Arrays.asList(node));
			List<Node> subgraph = new ArrayList<>(Arrays.asList(node));
			while (!queue.isEmpty())
				for (Node neighbor : queue.poll().neighbors)
					if (neighbor.color != TAGGED) {
						neighbor.color = TAGGED;
						queue.add(neighbor);
						subgraph.add(neighbor);
					}
			subgraphs.add(subgraph);
		}
		return subgraphs;
	}

	public static void buildGraph(List<Node> nodes) {
		for (int i = 0; i < nodes.size(); ++i) {
			Node a = nodes.get(i);
			for (int j = i + 1; j < nodes.size(); ++j) {
				Node b = nodes.get(j);
				if (areNeighbors(a, b)) {
					a.neighbors.add(b);
					b.neighbors.add(a);
				}
			}
		}
	}

	public static boolean areNeighbors(Node a, Node b) {
		String c = a.word, d = b.word;
		int diff = 0;
		for (int i = 0; i < c.length(); ++i) if (c.charAt(i) != d.charAt(i)) ++diff;
		return diff == 2;
	}

	public static void scoreGraph(List<Node> nodes, Node n, int blue, int red) {
		if (n.score > 0) return;
		n.color = blue;
		Queue<Node> queue = new LinkedList<>(Arrays.asList(n));
		while (!queue.isEmpty()) {
			Node node = queue.poll();
			for (Node neighbor : node.neighbors)
				if (neighbor.color != blue && neighbor.color != red) {
					neighbor.color = node.color == red ? blue : red;
					queue.add(neighbor);
				}
		}
		int score = 0;
		for (Node node : nodes) if (node.color != red) ++score;
		for (Node node : nodes) if (node.color == blue) node.score = score;
	}
}