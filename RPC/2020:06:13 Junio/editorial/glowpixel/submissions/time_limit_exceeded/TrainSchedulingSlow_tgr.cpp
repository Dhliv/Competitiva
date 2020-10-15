#include <iostream>
#include <vector>
using namespace std ;
typedef long long ll ;
int main(int argc, char *argv[]) {
   int n ;
   cin >> n ;
   vector<char> typ(n) ;
   vector<int> t0(n) ;
   vector<int> len(n) ;
   vector<int> coor(n) ;
   for (int i=0; i<n; i++)
      cin >> typ[i] >> t0[i] >> len[i] >> coor[i] ;
   ll rr = 0 ;
   for (int i=0; i<n; i++)
      for (int j=i+1; j<n; j++) {
         if (typ[i] == typ[j]) {
            if (coor[i] == coor[j] && t0[i] + len[i] > t0[j] && t0[j] + len[j] > t0[i]) {
// disable this; only do h vs v
//             rr++ ;
            }
         } else {
            if (t0[i] + len[i] - coor[i] > t0[j] - coor[j] && t0[j] + len[j] - coor[j] > t0[i] - coor[i]) {
               rr++ ;
            }
         }
      }
   cout << rr << endl ;
}
