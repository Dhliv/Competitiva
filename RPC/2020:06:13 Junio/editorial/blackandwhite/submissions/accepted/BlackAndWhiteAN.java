import java.util.*;

public class BlackAndWhiteAN {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int N = s.nextInt();
    boolean[][] arr = new boolean[N][N];
    for (int i = 0; i < N; i++) {
      String line = s.next();
      for (int j = 0; j < N; j++) {
        arr[i][j] = line.charAt(j) == 'B';
      }
    }

    boolean ok = true;
    for (int r = 0; r < N; r++) {
      int tb = 0, tw = 0, cb = 0, cw = 0;
      for (int c = 0; c < N; c++) {
        if (arr[r][c]) {
          tb++;
          cb++;
          cw = 0;
          if (cb == 3) ok = false;
        } else {
          tw++;
          cw++;
          cb = 0;
          if (cw == 3) ok = false;
        }
      }
      if (tb != tw) ok = false;
    }

    for (int c = 0; c < N; c++) {
      int tb = 0, tw = 0, cb = 0, cw = 0;
      for (int r = 0; r < N; r++) {
        if (arr[r][c]) {
          tb++;
          cb++;
          cw = 0;
          if (cb == 3) ok = false;
        } else {
          tw++;
          cw++;
          cb = 0;
          if (cw == 3) ok = false;
        }
      }
      if (tb != tw) ok = false;
    }

    System.out.println(ok ? "1" : "0");
  }
}
