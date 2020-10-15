import java.util.*;
public class issuing_plates_xiaowuc1 {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    mapping = new char[256];
    for(int i = 0; i < 256; i++) mapping[i] = (char)i;
    mapping['0'] = 'O';
    mapping['1'] = 'L';
    mapping['2'] = 'Z';
    mapping['3'] = 'E';
    mapping['5'] = 'S';
    mapping['6'] = 'B';
    mapping['7'] = 'T';
    mapping['8'] = 'B';
    ArrayList<String> bad = new ArrayList<>();
    int n = sc.nextInt();
    int m = sc.nextInt();
    while(n-- > 0) bad.add(sc.next());
    while(m-- > 0) {
      String cand = cleanse(sc.next());
      boolean ret = false;
      for(String out: bad) ret |= cand.indexOf(out) >= 0;
      System.out.println(ret ? "INVALID" : "VALID");
    }
  }
  static char[] mapping;
  public static String cleanse(String in) {
    String ret = "";
    for(int i = 0; i < in.length(); i++) ret += mapping[in.charAt(i)];
    return ret;
  }
}
