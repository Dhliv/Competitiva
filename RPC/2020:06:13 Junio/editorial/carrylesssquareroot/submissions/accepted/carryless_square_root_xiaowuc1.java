import java.util.*;
public class carryless_square_root_xiaowuc1 {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    String want = new StringBuilder(sc.next()).reverse().toString();
    if(want.length() % 2 == 0) fail();
    int[] ret = new int[want.length()/2+1];
    Arrays.fill(ret, -1);
    if(!dfs(ret, ret.length-1, want)) fail();
    for(int i = ret.length-1; i >= 0; i--) System.out.print(ret[i]);
    System.out.println();
  }
  public static void fail() {
    System.out.println("-1");
    System.exit(0);
  }
  public static boolean dfs(int[] ret, int idx, String want) {
    if(idx < 0) return true;
    for(int k = idx == ret.length-1 ? 1 : 0; k < 10; k++) {
      ret[idx] = k;
      int[] sums = new int[want.length()];
      for(int i = 0; i < ret.length; i++) {
        for(int j = 0; j < ret.length; j++) {
          if(ret[i] < 0 || ret[j] < 0 || sums[i+j] < 0) sums[i+j] = -1;
          else {
            sums[i+j] += ret[i]*ret[j];
            sums[i+j] %= 10;
          }
        }
      }
      boolean good = true;
      for(int i = 0; i < sums.length && good; i++) {
        if(sums[i] < 0) continue;
        good = want.charAt(i)-'0' == sums[i];
      }
      if(good && dfs(ret, idx-1, want)) return true;
      ret[idx] = -1;
    }
    return false;
  }
}
