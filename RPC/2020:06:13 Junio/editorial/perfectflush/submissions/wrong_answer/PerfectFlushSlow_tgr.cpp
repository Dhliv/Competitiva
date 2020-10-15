#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int n, k ;
   cin >> k >> n ;
   vector<int> v(n) ;
   for (auto &a : v)
      cin >> a ;
   vector<int> r ;
   vector<int> seen(k) ;
   int st = 0 ;
   for (int cookie=1; (int)r.size() < k; cookie++) {
      int need = k-r.size() ;
      int at = n ;
      while (need > 0 && at > 0) {
         at-- ;
         if (seen[v[at]] < cookie) {
            seen[v[at]] = cookie ;
            need-- ;
         }
      }
      int smi = -1 ;
      for (int i=st; i<=at; i++)
         if (seen[v[i]] != n+1 && (smi < 0 || v[i] < v[smi]))
            smi = i ;
      r.push_back(v[smi]) ;
      st = smi + 1 ;
      seen[v[smi]] = n+1 ;
   }
   for (int i=0; i<(int)r.size(); i++)
      cout << " " << r[i] ;
   cout << endl ;
}
