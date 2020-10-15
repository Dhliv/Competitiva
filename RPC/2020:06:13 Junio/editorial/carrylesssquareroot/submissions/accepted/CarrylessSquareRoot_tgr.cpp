#include <iostream>
#include <string>
using namespace std ;
string s, t, r ;
int sqr(int at) {
   int sum = 0 ;
   for (int i=max(0, at-(int)r.size()); i <= at && i<(int)r.size(); i++)
      sum += r[i] * r[at-i] ;
   return s[at] == sum % 10 ;
}
int dfs(int at) {
   if (at >= (int)r.size()) {
      for (; at < (int)s.size(); at++)
         if (!sqr(at))
            return 0 ;
      return 1 ;
   }
   for (int d=0; d<10; d++) {
      r[at] = d ;
      if (!sqr(at))
         continue ;
      int t = dfs(at+1) ;
      if (t)
         return 1 ;
   }
   return 0 ;
}
int main() {
   cin >> s ;
   if (s.size() & 1) {
      t.resize(s.size()) ;
      for (auto &v : s)
         v -= '0' ;
      int rsz = (1+s.size()) >> 1 ;
      r.resize(rsz) ;
      if (dfs(0)) {
         for (auto &v : r)
            v += '0' ;
         cout << r << endl ;
         exit(0) ;
      }
   }
   cout << "-1" << endl ;
}
