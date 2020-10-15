#include <iostream>
#include <string>
#include <vector>
using namespace std ;
int w, h ;
vector<int> head ;
int encode(int i, int j) {
   return i + h * j ;
}
int gethead(int v) {
   int h = head[v] ;
   if (h != head[h])
      h = gethead(h) ;
   head[v] = h ;
   return h ;
}
void connect(int a, int b) {
   int ah = gethead(a) ;
   int bh = gethead(b) ;
   if (ah != bh) {
      if (ah < bh) {
         head[bh] = ah ;
      } else {
         head[ah] = bh ;
      }
   }
}
int main() {
   int R, C ;
   cin >> R >> C ;
   vector<string> maze ;
   string t ;
   maze.push_back("") ;
   for (int i=0; i<R; i++) {
      cin >> t ;
      t.insert(t.begin(), '.') ;
      t.push_back('.') ;
      maze.push_back(t) ;
   }
   maze.push_back("") ;
   int odd = 0 ;
   for (int i=0; i<(int)maze.size(); i++)
      for (int j=0; j<(int)maze[i].size(); j++)
         if (maze[i][j] == '/')
            odd = (i ^ j) & 1 ;
         else if (maze[i][j] == '\\')
            odd = (1 ^ i ^ j) & 1 ;
   h = maze.size() + 1 ;
   w = 0 ;
   for (auto s : maze)
      w = max(w, (int)s.size()) ;
   w++ ;
   head.resize(w*h) ;
   for (int i=0; i<(int)head.size(); i++)
      head[i] = -1 ;
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         if (0 == ((i ^ j ^ odd) & 1))
            head[encode(i,j)] = encode(i,j) ;
   for (int i=0; i<h-1; i++)
      for (int j=0; j<w-1; j++) {
         int c = '.' ;
         if (j < (int)maze[i].size())
            c = maze[i][j] ;
         if (c == '.') {
            if (0 == ((i ^ j ^ odd) & 1))
               connect(encode(i, j), encode(i+1, j+1)) ;
            else
               connect(encode(i, j+1), encode(i+1, j)) ;
         }
      }
   int r = -1 ;
   for (int i=0; i<(int)head.size(); i++)
      if (head[i] == i)
         r++ ;
   cout << r << endl ;
}
