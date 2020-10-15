#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std ;
int main() {
   int n, k ;
   scanf("%d %d", &n, &k) ;
   vector<int> v(n) ;
   for (auto &a : v) {
      scanf("%d", &a) ;
      a-- ;
   }
   vector<int> r ;
   vector<char> seen(k) ;
   vector<int> nextlast(n) ;
   vector<int> next(n) ;
   vector<int> nextlink(k) ;
   for (auto &e : nextlink)
      e = -1 ;
   for (int i=n-1; i>=0; i--) {
      int e = v[i] ;
      next[i] = nextlink[e] ;
      nextlink[e] = i ;
   }
   int st = 0 ;
   int need = k ;
   int at = n ;
   int ptr = n ;
   while (need > 0 && at > 0) {
      at-- ;
      if (seen[v[at]] == 0) {
         nextlast[at] = ptr ;
         ptr = at ;
         seen[v[at]] = 2 ;
         need-- ;
      }
   }
   map<int, int> loc ;
   for (int i=0; i<=at; i++)
      if (loc.find(v[i]) == loc.end())
         loc[v[i]] = i ;
   while ((int)r.size() < k) {
      int smi = loc.begin()->second ;
      r.push_back(v[smi]) ;
      seen[v[smi]] = 1 ;
      loc.erase(v[smi]) ;
      while (at < n && seen[v[at]] == 1) {
         int nat = nextlast[at] ;
         for (int i=at+1; i<n && i<=nat; i++)
            if (seen[v[i]] != 1 && loc.find(v[i]) == loc.end())
               loc[v[i]] = i ;
         at = nat ;
      }
      while (st <= smi) {
         if (seen[v[st]] == 2) {
            int nv = next[st] ;
            if (nv >= 0 && nv <= at) {
               loc[v[st]] = nv ;
            } else {
               loc.erase(v[st]) ;
            }
         }
         st++ ;
      }
   }
   for (int i=0; i<(int)r.size(); i++)
      cout << " " << (1+r[i]) ;
   cout << endl ;
}
