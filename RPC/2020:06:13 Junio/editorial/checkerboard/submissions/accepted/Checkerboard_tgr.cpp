#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int R, C, A, B ;
   cin >> R >> C >> A >> B ;
   vector<int> a(A), b(B) ;
   for (auto &v : a)
      cin >> v ;
   for (auto &v : b)
      cin >> v ;
   int col = 1 ;
   for (int ai=0; ai<A; ai++) {
      for (int ac=0; ac<a[ai]; ac++) {
         int rcol = col ;
         for (int bi=0; bi<B; bi++) {
            for (int bc=0; bc<b[bi]; bc++)
               cout << (rcol ? 'B' : 'W') ;
            rcol = 1 - rcol ;
         }
         cout << endl ;
      }
      col = 1 - col ;
   }
}
