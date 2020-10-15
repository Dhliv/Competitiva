import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class MazeConnect_sjz {

    private BufferedReader in;
    private int nRows;
    private int nCols;
    private char[][] maze;
    
    
    
    public MazeConnect_sjz(BufferedReader input) {
        in = input;
    }


	public void solve() throws IOException {
        read();

        int n = countAreas();

        System.out.println (n);
    }



    private int countAreas() {
        fill(0,0);
        int numberOfAreas = 0;
        for (int y = 1; y < nRows+2; ++y) {
            for (int x = 1; x < nCols+2; ++x) {
                char c = maze[y][x];
                if (c == '.') {
                    ++numberOfAreas;
                    fill (x, y);
                } else if (c == '/' && isADiamond(x,y)) {
                    ++numberOfAreas;
                }
            }
        }
        return numberOfAreas;
    }


    private boolean isADiamond(int x, int y) {
        if (maze[y][x] == '/' && maze[y][x+1] == '\\') {
            return (maze[y+1][x] == '\\' && maze[y+1][x+1] == '/');
        } else
            return false;
    }

    private static class Coord {
        public Coord(int x2, int y2) {
            x = x2;
            y = y2;
        }
        int x;
        int y;
    }
    
    private void fill(int x, int y) {
        LinkedList<Coord> q = new LinkedList<>();
        q.add(new Coord(x,y));
        maze[y][x] = '#';
        while (!q.isEmpty()) {
            Coord xy = q.getFirst();
            q.removeFirst();
            check(xy.x+1, xy.y, q);
            check(xy.x-1, xy.y, q);
            check(xy.x, xy.y+1, q);
            check(xy.x, xy.y-1, q);
            int y1 = xy.y+1;
            if (y1 >= 0 && y1 < nRows+2) {
                if (maze[y1][xy.x] == '/')
                    check(xy.x-1, y1, q);
                else if (maze[y1][xy.x] == '\\')
                    check(xy.x+1, y1, q);
            }
            int ym1 = xy.y-1;
            if (ym1 >= 0 && ym1 < nRows+2) {
                if (maze[ym1][xy.x] == '/')
                    check(xy.x+1, ym1, q);
                else if (maze[ym1][xy.x] == '\\')
                    check(xy.x-1, ym1, q);
            }
        }
    }


    private void check(int x, int y, LinkedList<Coord> q) {
        if (y >= 0 && y < nRows+2) {
            if (x >= 0 && x < nCols+2) {
                if (maze[y][x] == '.') {
                    maze[y][x] = '#';
                    q.addLast(new Coord(x,y));
                }
            }
        }
    }


    private void read() throws IOException {
        String line = in.readLine();
        StringTokenizer tok = new StringTokenizer(line);
        nRows = Integer.parseInt(tok.nextToken());
        nCols = Integer.parseInt(tok.nextToken());
        
        maze = new char[nRows+2][nCols+2];
        
        for (int y = 0; y < nRows+2; ++y) {
            maze[y][0] = '.';
            maze[y][nCols+1] = '.';
        }
        for (int x = 0; x < nCols+2; ++x) {
            maze[0][x] = '.';
            maze[nRows+1][x] = '.';
        }
            
        
        for (int y = 1; y < nRows+1; ++y) {
            line = in.readLine();
            for (int x = 1; x < nCols+1; ++x)
                maze[y][x] = line.charAt(x-1);
        }
        in.close();
    }


    public static void main(String[] args) throws IOException {
        BufferedReader input;
        if (args.length > 0) {
            input = new BufferedReader(new FileReader(args[0]));
        } else {
            input = new BufferedReader (new InputStreamReader(System.in));
        }
        MazeConnect_sjz problem = new MazeConnect_sjz(input);
        problem.solve();
    }

}
