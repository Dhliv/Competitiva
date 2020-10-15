import java.io.PrintStream;
import java.util.Scanner;

/**
 * Solution to Black & White
 * 
 * @author vanb
 */
public class blackwhite_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    /**
     * Do it!
     */
    private void doit()
    {
        // Read the board
        int n = sc.nextInt();
        char board[][] = new char[n][];
        for( int i=0; i<n; i++ ) board[i] = sc.next().toCharArray();
        
        // Is this board OK?
        int ok = 1;
        
        // Check rows 
        for( int i=0; i<n; i++ )
        {
            // We want Bs and Ws to balance on each row
            int balance = 0;
            for( int j=0; j<n; j++ )
            {
                balance += board[i][j]=='B' ? 1 : -1;
                
                // Check for 3 consecutive of the same color
                if( j>1 && board[i][j]==board[i][j-1] && board[i][j]==board[i][j-2] ) ok = 0;
            }
            
            // Check the balance
            if( balance!=0 ) ok = 0;
        }
        
        // Check columns 
        for( int j=0; j<n; j++ )
        {
            // We want Bs and Ws to balance on each column
            int balance = 0;
            for( int i=0; i<n; i++ )
            {
                balance += board[i][j]=='B' ? 1 : -1;
                
                // Check for 3 consecutive of the same color
                if( i>1 && board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] ) ok = 0;
            }
            
            // Check the balance
            if( balance!=0 ) ok = 0;
        }
        
        ps.println( ok );
    }
        
    /**
     * Main.
     * 
     * @param args
     * @throws Exception
     */
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new blackwhite_vanb().doit();
    }

}
