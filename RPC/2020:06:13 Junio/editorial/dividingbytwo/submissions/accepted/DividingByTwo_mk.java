/**
 * Solution to Dividing By Two
 * @author Melanie Kirsche
 * 
 * If a < b, dividing by two only makes things worse, so the answer is b - a.
 * 
 * In the case that a > b, the key observation is that adding to an even number
 * is never worthwhile.  To see this, note that adding 2 and then dividing
 * by 2, which takes 3 moves, is equivalent to dividing by 2 then adding 1,
 * which requires only two moves.  That is, for any x, (x + 1 + 1)/2 = x/2 + 1.
 */
import java.util.*;
public class DividingByTwo_mk {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	long a = input.nextLong(), b = input.nextLong();
	System.out.println(numberOfMoves(a, b));
}
/*
 * The number of moves required to get from a to b.
 */
static long numberOfMoves(long a, long b)
{
	if(a <= b) return b - a;
	if(a%2 == 1) return 1 + numberOfMoves(a+1, b); // have to add when a is odd
	return 1 + numberOfMoves(a/2, b); // always divide even numbers when a > b
}
}
