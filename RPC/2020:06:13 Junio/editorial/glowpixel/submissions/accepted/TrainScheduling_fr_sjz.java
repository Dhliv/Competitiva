import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TrainScheduling_fr_sjz {



	
    private BufferedReader in;
    
    public TrainScheduling_fr_sjz(BufferedReader input) {
        in = input;
    }


	static class FastReader
	// from https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(BufferedReader in) 
        { 
            br = in;
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 

	
    
    public static class Event implements Comparable<Event> {
        public int time;
        public char orientation;
        public boolean entering;
        
        public Event(int t0, char orientation0, boolean entering0) {
            time = t0;
            orientation = orientation0;
            entering = entering0;
        }

        @Override
        public int compareTo(Event ev) {
            return time - ev.time;
        }
        
        public String toString() {
            return "E:" + time + ":" + orientation + ":" + entering; 
        }
    }
    
    
    /**
     * A train in row r and a train in column c would collide at time t if
     * a train in row 0 starting r earlier would collide with a train in
     * column 0 starting c earlier would collide at time t.
     * 
     * If two trains in row and column 0 collide, they will do so at (0,0).
     * So we only need to know when each train occupies (0,0).
     * 
     * With these observations, we set up a discrete event simulation and track
     * the number of horizontal and vertical trains passing through (0,0) at
     * any moment.
     */
    public void solve() {
        ArrayList<Event> events = new ArrayList<>();
        FastReader input = new FastReader(in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            char orientation = input.next().charAt(0);
            int time = input.nextInt();
            int len = input.nextInt();
            int pos = input.nextInt();
            
            // To avoid any possible issues with ties, I am doubling the
            // times and making all trains enter on an even time and leave on
            // an odd time.
            events.add(new Event(2*(time-pos), 
                    orientation, true)); // train enters (0,0)
            events.add(new Event(2*(time+len-pos)-1, 
                    orientation, false)); // train false (0,0)
        }

        Collections.sort(events);
        
        // run the simulation
        int horizontalTrains = 0;
        int verticalTrains = 0;
        long collisions = 0;
        for (Event ev: events) {
            if (ev.entering) {
                if (ev.orientation == 'h') {
                    ++horizontalTrains;
                    collisions += (long)verticalTrains;
                } else {
                    ++verticalTrains;
                    collisions += (long)horizontalTrains;
                }
            } else {
                if (ev.orientation == 'h') {
                    --horizontalTrains;
                } else {
                    --verticalTrains;
                }
            }
        }
        System.out.println(collisions);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader input;
        if (args.length > 0) {
            input = new BufferedReader(new FileReader(args[0]));
        } else {
            input = new BufferedReader (new InputStreamReader(System.in));
        }
        TrainScheduling_fr_sjz trainSched = new TrainScheduling_fr_sjz(input);
        trainSched.solve();
    }

}
