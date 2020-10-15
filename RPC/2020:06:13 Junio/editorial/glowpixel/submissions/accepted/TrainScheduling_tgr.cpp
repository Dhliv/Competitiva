#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
typedef long long ll ;
struct traininfo {
   int tim, end ;
   char typ ;
} ;
bool operator<(const traininfo &a, const traininfo &b) {
   if (a.tim != b.tim)
      return a.tim < b.tim ;
   if (a.end != b.end)
      return a.end < b.end ;
   return a.typ < b.typ ;
}
int main() {
   int n ;
   cin >> n ;
   vector<traininfo> sortme ;
   for (int i=0; i<n; i++) {
      char typ ;
      int t0, len, coor ;
      cin >> typ >> t0 >> len >> coor ;
      sortme.push_back({t0-coor, 1, typ}) ;
      sortme.push_back({t0-coor+len, -1, typ}) ;
   }
   sort(sortme.begin(), sortme.end()) ;
   ll rr = 0 ;
   ll hcnt = 0, vcnt = 0 ;
   for (auto v : sortme) {
      if (v.typ == 'h') {
         hcnt += v.end ;
         if (v.end > 0) {
            rr += vcnt ;
         }
      } else {
         vcnt += v.end ;
         if (v.end > 0)
            rr += hcnt ;
      }
   }
   cout << rr << endl ;
}
