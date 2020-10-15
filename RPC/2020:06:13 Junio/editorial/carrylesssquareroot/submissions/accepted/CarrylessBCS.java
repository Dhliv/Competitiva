import java.util.*;

class CarrylessBCS {
    static int[] solution;
    static String n;
    static int L;

    static boolean check() {
OUTER:
        for (int k = 0; k < 2*L-1; ++k) {
            int sum = 0;
            for (int i = 0; i <= k; ++i) {
                int j = k-i;
                if (i < 0 || i >= L || j < 0 || j >= L) continue;
                if (solution[i] == -1 || solution[j] == -1) continue OUTER;
                sum = (sum + solution[i] * solution[j]) % 10;
            }
            if (sum != n.charAt(k) - '0')
                return false;
        }
        return true;
    }

    static boolean backtrack(int idx) {
        if (idx == L) return true;
        for (int i = 0; i <= 9; ++i) {
            solution[idx] = i;
            if (check()) {
                if (backtrack(idx+1)) return true;
            }
        }
        solution[idx] = -1;
        return false;
    }
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        n = in.next();
        
        if (n.length() % 2 == 0) {
            System.out.println(-1);
        } else {
            L = (n.length()+1)/2;
            solution = new int[L];
            Arrays.fill(solution, -1);
            if(backtrack(0)) {
                for (int i = 0; i < L; ++i) {
                    System.out.print(solution[i]);
                }
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}
