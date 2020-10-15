import java.util.*;

public class CheckerboardAN {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int R = s.nextInt(), C = s.nextInt(), A = s.nextInt(), B = s.nextInt();
    int[] a = new int[A];
    int[] b = new int[B];
    for (int i = 0; i < A; i++) {
      a[i] = s.nextInt();
      if (i > 0) a[i] += a[i - 1];
    }
    for (int i = 0; i < B; i++) {
      b[i] = s.nextInt();
      if (i > 0) b[i] += b[i - 1];
    }
    for (int i = 1; i <= R; i++) {
      int ii = Arrays.binarySearch(a, i);
      if (ii < 0) ii = -1 - ii;
      for (int j = 1; j <= C; j++) {
        int jj = Arrays.binarySearch(b, j);
        if (jj < 0) jj = -1 - jj;
        int parity = ii + jj;
        System.out.print(parity % 2 == 0 ? "B" : "W");
      }
      System.out.println();
    }
  }
}
