using System;
public class evenorodd_xiaowuc1 {
  public static void Main(string[] args) {
    int n = int.Parse(Console.ReadLine());
    if(n%4 == 0) Console.WriteLine("Even");
    else if(n%2 == 0) Console.WriteLine("Odd");
    else Console.WriteLine("Either");
  }
}
