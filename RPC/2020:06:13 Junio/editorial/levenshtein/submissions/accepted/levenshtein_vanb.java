import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Solution to Levenshtein.
 *
 * @author vanb
 */
public class levenshtein_vanb
{
    
    /** The Input. */
    private static Scanner sc;
    
    /** The Output. */
    private static PrintStream ps;
    
    /**
     * Do it.
     */
    private void doit()
    {
        char alphabet[] = sc.next().toCharArray();
        String word = sc.next();
        
        // Use a set to avoid duplicates
        HashSet<String> words = new HashSet<String>();
        
        // Add a letter
        for( int i = 0; i<word.length()+1; i++ )
        {
            for( char letter : alphabet )
            {
                words.add( word.substring( 0, i ) + letter + word.substring( i ) );
            }
        }
        
        //Remove a letter
        for( int i = 0; i<word.length(); i++ )
        {
            words.add( word.substring( 0, i ) + word.substring( i+1 ) );
        }
        
        // Substitute a letter
        for( int i = 0; i<word.length(); i++ )
        {
            for( char letter : alphabet )
            {
                words.add( word.substring( 0, i ) + letter + word.substring( i+1 ) );
            }
        }
        
        // Remove the original word
        words.remove( word );
        
        // Turn the set into a list and sort it
        String list[] = (String[])words.toArray( new String[words.size()] );
        Arrays.sort( list );
        
        for( String newword : list ) ps.println( newword );
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
        
        new levenshtein_vanb().doit();
   //   System.err.println(Character.MAX_RADIX);

    }

}
