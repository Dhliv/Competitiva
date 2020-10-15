/**
 * Solution to Rainbow Strings
 * @author Melanie Kirsche
 * 
 * For every unique character c in the string, a rainbow string can include any
 * single instance of c, or none at all, for a total of frequency(c) + 1 options
 * Each character can be considered independently, so the answer is: 
 * (frequency(a) + 1) * (frequency(b) + 1) * ... * (frequency(z) + 1)
 */
import java.util.*;
public class RainbowStrings_mk {
	static long MOD = 11092019 ;
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	
	// Read input
	char[] s = input.next().toCharArray();
	
	// Count frequency of each character
	int[] fs = new int[256];
	for(char c : s) fs[c]++;
	
	// Compute total number of rainbow strings using formula above
	long res = 1L;
	for(int f : fs) res = (res * (f + 1))%MOD;
	
	// Output answer
	System.out.println(res);
}
}
