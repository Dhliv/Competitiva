#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
struct quad {
   int cmd, i, p, r ;
} ;
template<typename T> struct BIT {
   BIT<T>(int n=0) { resize(n) ; }
   void resize(int n) {
      sz = n ;
      arr.resize(4*n+1) ;
   }
   void dorange(int a, int b, int v) {
      while (a < b) {
         int lowb = a & -a ;
         if (lowb == 0) {
            lowb = b + b ;
            while (lowb & (lowb - 1))
               lowb &= lowb-1 ;
         }
         while (a + lowb > b)
            lowb >>= 1 ;
         arr[2*a+lowb].update(v) ;
         a += lowb ;
      }
   }
   int accum(int a) {
      int r = T::zero ;
      for (int b=1; b<2*sz; b *= 2) {
         r = T::sum(r, arr[2*a+b]) ;
         a &= ~b ;
      }
      return r ;
   }
   int sz ;
   vector<T> arr ;
} ;
struct bitsum {
   bitsum() : d(zero) {}
   void update(int v) { d += v ; }
   static int sum(int a, const bitsum &b) { return a+b.d ; }
   static const int zero = 0 ;
   int d ;
} ;
struct bitmax {
   bitmax() : d(zero) {}
   void update(int v) { d = v ; }
   static int sum(int a, const bitmax &b) { return max(a, b.d) ; }
   static const int zero = -1 ;
   int d ;
} ;
int main() {
   int n, m, q ;
   cin >> n >> m >> q ;
   vector<vector<int> > dat(m) ;
   BIT<bitmax> bm(n) ;
   vector<BIT<bitsum> > bsv(m) ;
   for (int i=0; i<m; i++) {
      int ts ;
      cin >> ts ;
      bsv[i].resize(ts) ;
      auto &v = dat[i] ;
      v.resize(ts) ;
      for (auto &u : v)
         cin >> u ;
   }
   vector<quad> cmds(q) ;
   vector<pair<int,int> > setvals ;
   for (int i=0; i<(int)cmds.size(); i++) {
      auto &v = cmds[i] ;
      cin >> v.cmd ;
      switch (v.cmd) {
case 1: cin >> v.i >> v.p ; v.i-- ; v.p-- ;
        bm.dorange(v.p, v.p+dat[v.i].size(), i) ;
        break ;
case 2: cin >> v.p ; v.p-- ;
        {
           int ci = bm.accum(v.p) ;
           if (ci < 0) {
              v.r = 0 ;
           } else {
              v.i = cmds[ci].i ;
              v.p -= cmds[ci].p ;
              setvals.push_back({ci, i}) ;
           }
        }
        break ;
case 3: cin >> v.i >> v.p >> v.r ; v.i-- ; v.p-- ; v.r-- ;
        break ;
      }
   }
   sort(setvals.begin(), setvals.end()) ;
   int svat = 0 ;
   for (int i=0; i<(int)cmds.size(); i++) {
      while (svat < (int)setvals.size() && setvals[svat].first == i) {
         int ci = setvals[svat++].second ;
         int di = cmds[i].i ;
         int add = cmds[ci].p ;
         cmds[ci].r = (bsv[di].accum(add) + dat[di][add]) % 256 ;
      }
      auto &v = cmds[i] ;
      if (v.cmd == 3)
         bsv[v.i].dorange(v.p, v.r+1, 1) ;
   }
   for (int i=0; i<(int)cmds.size(); i++)
      if (cmds[i].cmd == 2)
         cout << cmds[i].r << endl ;
}
