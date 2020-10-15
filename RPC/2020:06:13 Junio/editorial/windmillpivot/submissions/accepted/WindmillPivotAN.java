import java.awt.Point;
import java.util.*;

// orient 0 = pivot -> next
// orient 1 = pivot <- next
public class WindmillPivotAN {
  static int N;
  static boolean[][][] visited ;
  static Point[] p ;
  static int[] nl ;
  static int[] nr ;
  static Point[][] sortl ;
  static Point[][] sortr ;
  static Comparator[] c ;
  static Map<Point, Integer> lookup = new HashMap<Point, Integer>();

  static int det(int a, int b, int c, int d) {
    return a * d - b * c;
  }

  static Comparator<Point> cmp(Point pvt) {
    return new Comparator<Point>() {
      public int compare(Point a, Point b) {
        return det(a.x - pvt.x, a.y - pvt.y, b.x - pvt.x, b.y - pvt.y);
      }
    };
  }

  static Point mirror(Point origin, Point pt) {
    return new Point(2 * origin.x - pt.x, 2 * origin.y - pt.y);
  }

  static Point getLeft(int pivot, int idx) {
    if (idx == nl[pivot]) {
      if (nr[pivot] == 0) {
        return sortl[pivot][0];
      } else {
        return sortr[pivot][0];
      }
    } else {
      return sortl[pivot][idx];
    }
  }

  static Point getRight(int pivot, int idx) {
    if (idx == nr[pivot]) {
      if (nl[pivot] == 0) {
        return sortr[pivot][0];
      } else {
        return sortl[pivot][0];
      }
    } else {
      return sortr[pivot][idx];
    }
  }
  static int[] score ;
  static int computeScore(int orient, int pivot, int next) {
    if (visited[orient][pivot][next]) return 0;
    Arrays.fill(score, 0, N, 0);
    while (!visited[orient][pivot][next]) {
      visited[orient][pivot][next] = true;
      score[pivot]++;

      // exactly one of the next two is nonnegative
      int left = Arrays.binarySearch(sortl[next], 0, nl[next], p[pivot], c[next]);
      int right = Arrays.binarySearch(sortr[next], 0, nr[next], p[pivot], c[next]);
      Point mainCandidate = null;
      Point mirrorCandidate = null;
      Point mirrorPivot = mirror(p[next], p[pivot]);
      int mirrorLeft = -Arrays.binarySearch(sortl[next], 0, nl[next], mirrorPivot, c[next]) - 1;
      int mirrorRight = -Arrays.binarySearch(sortr[next], 0, nr[next], mirrorPivot, c[next]) - 1;
      if (left >= 0) {
        mainCandidate = getLeft(next, left + 1);
        mirrorCandidate = getRight(next, mirrorRight);
      } else {
        mainCandidate = getRight(next, right + 1);
        mirrorCandidate = getLeft(next, mirrorLeft);
      }
      Point mirrorMirrorCandidate = mirror(p[next], mirrorCandidate);
      pivot = next;
      if (c[next].compare(mainCandidate, mirrorMirrorCandidate) < 0) {
        next = lookup.get(mainCandidate);
        orient = 1 - orient;
      } else {
        next = lookup.get(mirrorCandidate);
      }
    }
    int best = 0;
    for (int i = 0; i < N; i++) best = Math.max(best, score[i]);
    return best;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    N = s.nextInt();
    visited = new boolean[2][N][N];
    p = new Point[N];
    nl = new int[N];
    nr = new int[N];
    sortl = new Point[N][N];
    sortr = new Point[N][N];
    score = new int[N] ;
    c = new Comparator[N];
    for (int i = 0; i < N; i++) {
      p[i] = new Point(s.nextInt(), s.nextInt());
      c[i] = cmp(p[i]);
      lookup.put(p[i], i);
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (p[j].x < p[i].x || (p[j].x == p[i].x && p[j].y < p[i].y)) {
          sortl[i][nl[i]++] = p[j];
        } else {
          sortr[i][nr[i]++] = p[j];
        }
      }

      Arrays.sort(sortl[i], 0, nl[i], c[i]);
      Arrays.sort(sortr[i], 0, nr[i], c[i]);
    }

    int best = 0;
    for (int o = 0; o < 2; o++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (i == j) continue;
          best = Math.max(best, computeScore(o, i, j));
        }
      }
    }

    System.out.println(best);
  }
}
