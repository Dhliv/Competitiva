import java.io.*;
import java.util.*;
public class perfect_flush_xiaowuc1 {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[] l = new int[n];
    int[] amtLeft = new int[k+1];
    boolean[] present = new boolean[k+1];
    for(int i = 0; i < n; i++) amtLeft[l[i] = Integer.parseInt(br.readLine())]++;
    ArrayList<Integer> ret = new ArrayList<>();
    for(int out: l) {
      amtLeft[out]--;
      if(present[out]) continue;
      while(!ret.isEmpty() && amtLeft[ret.get(ret.size()-1)] > 0 && out < ret.get(ret.size()-1)) {
        present[ret.remove(ret.size()-1)] = false;
      }
      present[out] = true;
      ret.add(out);
    }
    for(int i = 0; i < k; i++) {
      if(i > 0) System.out.print(" ");
      System.out.print(ret.get(i));
    }
    System.out.println();
  }
}
