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
   vector<char> seen(k) ;
   vector<int> next(n) ;
   int st = 0 ;
   int need = k ;
   int at = n ;
   int ptr = n ;
   while (need > 0 && at > 0) {
      at-- ;
      if (seen[v[at]] == 0) {
         next[at] = ptr ;
         ptr = at ;
         seen[v[at]] = 2 ;
         need-- ;
      }
   }
   while ((int)r.size() < k) {
      while (at < n && seen[v[at]] == 1)
         at = next[at] ;
      int smi = -1 ;
      for (int i=st; i<=at; i++)
         if (seen[v[i]] != 1 && (smi < 0 || v[i] < v[smi]))
            smi = i ;
      r.push_back(v[smi]) ;
      st = smi + 1 ;
      seen[v[smi]] = 1 ;
   }
   for (int i=0; i<(int)r.size(); i++)
      cout << " " << r[i] ;
   cout << endl ;
}
