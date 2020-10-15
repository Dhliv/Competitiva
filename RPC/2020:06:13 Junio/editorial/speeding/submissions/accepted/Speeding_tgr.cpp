#include <iostream>
using namespace std ;
int main() {
   int n ;
   int r = 0 ;
   cin >> n ;
   int ot, oloc ;
   cin >> ot >> oloc ;
   for (int i=1; i<n; i++) {
      int t, loc ;
      cin >> t >> loc ;
      r = max(r, (loc-oloc)/(t-ot)) ;
      ot = t ;
      oloc = loc ;
   }
   cout << r << endl ;
}
