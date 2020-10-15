#include <iostream>
using namespace std ;
int main() {
   int n ;
   cin >> n ;
   int t0 = 0 ;
   int t1 = 0 ;
   for (int i=0; i<n; i++) {
      t0 += i ;
      t1 += i+1 ;
   }
   t0 &= 1 ;
   t1 &= 1 ;
   if (t0 != t1)
      cout << "Either" << endl ;
   else if (t0 & 1)
      cout << "Odd" << endl ;
   else
      cout << "Even" << endl ;
}
