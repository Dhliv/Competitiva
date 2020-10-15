#include <vector>
#include <string>
#include <iostream>
using namespace std ;
int main() {
   int n ;
   cin >> n ;
   vector<string> b(n) ;
   for (auto &v : b)
      cin >> v ;
   int good = 1 ;
   for (int i=0; i<n; i++) {
      int sr=0, sc=0 ;
      for (int j=0; j<n; j++) {
         sr += (b[i][j] == 'B') ;
         sc += (b[j][i] == 'B') ;
      }
      for (int j=0; j+2<n; j++) {
         if (b[i][j] == b[i][j+1] && b[i][j] == b[i][j+2])
            good = 0 ;
         if (b[j][i] == b[j+1][i] && b[j][i] == b[j+2][i])
            good = 0 ;
      }
      if (sr + sr != n || sc + sc != n)
         good = 0 ;
   }
   cout << good << endl ;
}
