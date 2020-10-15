#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
typedef long long ll ;
int main(int argc, char *argv[]) {
   int n = atoll(argv[1]) ;
   int p = atoll(argv[2]) ;
   ll seq = atoll(argv[3]) ;
   vector<int> perm(n) ;
   for (int i=0; i<n; i++)
      perm[i] = i ;
   do {
      int s = 0 ;
      for (int i=0; i<n; i++)
         if (perm[i] == i)
            s++ ;
      if (s == p && --seq == 0) {
         for (int i=0; i<n; i++)
            cout << " " << (1+perm[i]) ;
         cout << endl ;
         exit(0) ;
      }
   } while (next_permutation(perm.begin(), perm.end())) ;
   cout << "No solution." << endl ;
}
