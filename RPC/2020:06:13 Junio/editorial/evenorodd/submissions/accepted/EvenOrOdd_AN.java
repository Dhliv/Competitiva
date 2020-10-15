import java.util.*;

public class EvenOrOdd_AN {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int N = s.nextInt();
    if (N % 4 == 0) System.out.println("Even");
    else if (N % 2 == 0) System.out.println("Odd");
    else System.out.println("Either");
  }
}
