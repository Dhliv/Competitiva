import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Rainbow Strings.
 *
 * @author vanb
 */
public class rainbow_vanb
{
    
    /** The Input. */
    private static Scanner sc;
    
    /** The Output. */
    private static PrintStream ps;
    
    /** The modulus. */
    private static final long MOD = 11092019 ;
    
    /** The letter counts. */
    private long counts[] = new long[36];
    
    /**
     * Count the number of ways of choosing 0 or 1 of each letter.
     *
     * @param level the level of recursion
     * @return the count from this level to the end
     */
    private long count( int level )
    {
        long result = 0L;
        if( level>0 )
        {
            --level;
            result = counts[level];
            result += ((result+1L)*count(level)) % MOD;
            result %= MOD;
        }
        
        return result;
    }
    
    /**
     * Doit.
     */
    private void doit()
    {
        char string[] = sc.next().toLowerCase().toCharArray();
        
        // Count the number of occurrences of each letter
        Arrays.fill( counts, 0 );
        for( char ch : string ) ++counts[Character.isLetter(ch) ? (int)(ch-'a') : ((int)(ch-'0')+26)];
        
        // Count the number of ways of choosing 0 or 1 of each letter
        // We've got to add 1 to account for not choosing any letter (i.e. the empty string)
        ps.println( (1L+count(36)) % MOD );
    }
        
    /**
     * The main method.
     *
     * @param args the arguments
     * @throws Exception the exception
     */
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new rainbow_vanb().doit();
    }

}
