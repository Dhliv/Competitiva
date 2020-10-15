import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Rainbow Strings.
 *
 * @author vanb
 */
public class rainbow_slow_vanb
{
    
    /** The Input. */
    private static Scanner sc;
    
    /** The Output. */
    private static PrintStream ps;
    
    /** The modulus. */
    private static final long MOD = 998244353L;
    
    /** The letter counts. */
    private long counts[] = new long[36];
    
    /** The answer. */
    private long answer = 0L;
    
    /**
     * Count the number of ways of choosing 0 or 1 of each letter.
     *
     * @param sofar The count so far
     * @param level the level of recursion
     */
    private void count( long sofar, int level )
    {
        if( level==0 ) 
        {
            answer += sofar;
            answer %= MOD;
        }
        else
        {
            --level;
            
            // Choose 0 of this letter
            count( sofar, level );
            
            // Choose 1 of this letter
            count( (sofar*counts[level]) % MOD, level );
        }
    }
    
    /**
     * Doit.
     */
    private void doit()
    {
        char string[] = sc.next().toLowerCase().toCharArray();
        
        // Count the number of occurrences of each letter
        Arrays.fill( counts, 0 );
        for( char ch : string ) ++counts[(int)(ch-'a')];
        
        // Count the number of ways of choosing 0 or 1 of each letter
        count( 1L, 36 );
        
        ps.println( answer );
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
        
        new rainbow_slow_vanb().doit();
    }

}
