import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Morse Redux.
 *
 * @author vanb
 */
public class morse_vanb
{
    
    /** The Input. */
    private static Scanner sc;
    
    /** The Output. */
    private static PrintStream ps;
    
    /** The Morse Code Patterns. We only need 26, so this is more than enough. */
    private char patterns[][] = 
    {
        ".".toCharArray(),
        "_".toCharArray(),
        "..".toCharArray(),
        "._".toCharArray(),
        "_.".toCharArray(),
        "__".toCharArray(),
        "...".toCharArray(),
        ".._".toCharArray(),
        "._.".toCharArray(),
        ".__".toCharArray(),
        "_..".toCharArray(),
        "_._".toCharArray(),
        "__.".toCharArray(),
        "___".toCharArray(),
        "....".toCharArray(),
        "..._".toCharArray(),
        ".._.".toCharArray(),
        "..__".toCharArray(),
        "._..".toCharArray(),
        "._._".toCharArray(),
        ".__.".toCharArray(),
        ".___".toCharArray(),
        "_...".toCharArray(),
        "_.._".toCharArray(),
        "_._.".toCharArray(),
        "_.__".toCharArray(),
        "__..".toCharArray(),
        "__._".toCharArray(),
        "___.".toCharArray(),
        "____".toCharArray(),
        ".....".toCharArray(),
        "...._".toCharArray(),
        "..._.".toCharArray(),
        "...__".toCharArray(),
        ".._..".toCharArray(),
        ".._._".toCharArray(),
        "..__.".toCharArray(),
        "..___".toCharArray(),
        "._...".toCharArray(),
        "._.._".toCharArray(),
        "._._.".toCharArray(),
        "._.__".toCharArray(),
        ".__..".toCharArray(),
        ".__._".toCharArray(),
        ".___.".toCharArray(),
        ".____".toCharArray(),
        "_....".toCharArray(),
        "_..._".toCharArray(),
        "_.._.".toCharArray(),
        "_..__".toCharArray(),
        "_._..".toCharArray(),
        "_._._".toCharArray(),
        "_.__.".toCharArray(),
        "_.___".toCharArray(),
        "__...".toCharArray(),
        "__.._".toCharArray(),
        "__._.".toCharArray(),
        "__.__".toCharArray(),
        "___..".toCharArray(),
        "___._".toCharArray(),
        "____.".toCharArray(),
        "_____".toCharArray()
    };
        
    /**
     * Do it.
     */
    private void doit()
    {
        // Figure out the lengths of each of the patterns.
        int lengths[] = new int[patterns.length];
        for( int i=0; i<patterns.length; i++ )
        {
            // First account for the spaces between dots/dashes
            lengths[i] = patterns[i].length-1;
            
            // Now, count up the dots/dashes (dashes count 3)
            for( int j=0; j<patterns[i].length; j++ ) lengths[i] += patterns[i][j]=='.' ? 1 : 3;   
         }
                
        // Sort them, shortest first
        Arrays.sort( lengths );
              
        // Read the input, count the number of occurrences of each letter
        int counts[] = new int[26];
        Arrays.fill( counts, 0 );
        char input[] = sc.nextLine().trim().toUpperCase().toCharArray();
        int letters = 0;
        for( char ch : input ) if( Character.isAlphabetic( ch ) ) 
        {
            ++letters;
            ++counts[(int)(ch-'A')];
        }

        Arrays.sort( counts );
        
        // Get the total length. Start with the number of spaces between letters (they count 3 each)
        int total = (letters-1)*3;
        
        // Now, match the smallest length with the most frequent letter
        for( int i=0; i<26; i++ ) total += lengths[i]*counts[25-i];
        
        ps.println( total );  
    }
        
    /**
     * The main method.
     *
     * @param args the arguments, not used
     * @throws Exception the exception
     */
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new morse_vanb().doit();
    }

}
