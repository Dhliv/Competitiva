#include <iostream>
using namespace std ;
using ll = long long ;
int main() {
   ll a, b ;
   cin >> a >> b ;
   ll r = 0 ;
   while (a != b) {
      if (a < b) {
         r += b-a ;
         a += b-a ;
      } else if (a & 1) {
         r++ ;
         a++ ;
      } else {
         r++ ;
         a >>= 1 ;
      }
   }
   cout << r << endl ;
}
