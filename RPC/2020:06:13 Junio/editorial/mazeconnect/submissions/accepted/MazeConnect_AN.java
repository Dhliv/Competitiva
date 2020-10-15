import java.util.*;

public class MazeConnect_AN {
  static String[] stringRows;
  static int[][] component;
  static char[][] data;
  static int R, C;

  static void fill(int label, int r, int c) {
    if (r < 0 || c < 0 || r > R + 2 || c > C + 2) return;
    if (component[r][c] > 0) return;
    component[r][c] = label;
    if (r == 1 || r == R + 2 || c == 1 || c == C + 2 || (r > 0 && c > 0 && data[r-2][c-2] == '.'))
      fill(label, r - 1, c - 1); //up-left
    if (r == 0 || r == R + 1 || c == 1 || c == C + 2 || (r < R + 2 && c > 0 && data[r-1][c-2] == '.'))
      fill(label, r + 1, c - 1); //down-left
    if (r == 1 || r == R + 2 || c == 0 || c == C + 1 || (r > 0 && c < C + 2 && data[r-2][c-1] == '.'))
      fill(label, r - 1, c + 1); //up-right
    if (r == 0 || r == R + 1 || c == 0 || c == C + 1 || (r < R + 2 && c < C + 2 && data[r-1][c-1] == '.'))
      fill(label, r + 1, c + 1); //down-right
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    R = s.nextInt();
    C = s.nextInt();
    stringRows = new String[R];
    boolean odd = false;
    for (int i = 0; i < R; i++) {
      stringRows[i] = s.next();
      int j = stringRows[i].indexOf('/');
      if (j > -1) odd = (i + j) % 2 == 1;
    }
    if (odd) {
      for (int i = 0; i < R; i++) stringRows[i] = "." + stringRows[i];
      C++;
    }

    data = new char[R][];
    for (int i = 0; i < R; i++) data[i] = stringRows[i].toCharArray();

    component = new int[R + 3][C + 3];

    int nComponents = 0;
    for (int i = 0; i < R + 3; i++) {
      for (int j = 0; j < C + 3; j++) {
        if (component[i][j] > 0) continue;
        if ((i + j) % 2 == 1) continue;
        fill(++nComponents, i, j);
      }
    }

    System.out.println(nComponents - 1);
  }
}
