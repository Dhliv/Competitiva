
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {
    static int n;
    static int[]a, b;
    
    static int res;
    
    public static void main(String[]args) throws IOException{
        String[]data;
        BufferedReader f = new BufferedReader (new InputStreamReader(System.in));
        n = Integer.valueOf(f.readLine());
        a = new int[n];
        b = new int[n];
        data = f.readLine().split(" ");
        for(int i = 0 ; i < n ; ++i){
            a[i] = Integer.valueOf(data[i]);
        }
        
        data = f.readLine().split(" ");
        for(int i = 0 ; i < n ; ++i){
            b[i] = Integer.valueOf(data[i]);
        }
        res = 0;
        for(int i = 0 ; i < n ; ++i){
            int val = Integer.MAX_VALUE;
            for(int j = 0 ; j < n ; ++j){
                val = Math.min(Math.abs(a[i]-b[j]), val);
            }
            res = Math.max(val, res);
        }
        System.out.println(res);
    }
}
