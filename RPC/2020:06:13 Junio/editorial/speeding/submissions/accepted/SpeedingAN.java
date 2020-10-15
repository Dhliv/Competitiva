import java.util.*;

public class SpeedingAN {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int N = s.nextInt();
    int prevT = 0, prevD = 0;
    int bestSoFar = 0;
    for (int i = 0; i < N; i++) {
      int curT = s.nextInt(), curD = s.nextInt();
      if (curT == 0) continue;
      bestSoFar = Math.max(bestSoFar, (curD - prevD) / (curT - prevT));
      prevT = curT;
      prevD = curD;
    }
    System.out.println(bestSoFar);
  }
}
