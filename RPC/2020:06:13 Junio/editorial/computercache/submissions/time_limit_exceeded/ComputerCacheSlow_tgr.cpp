#include <iostream>
#include <vector>
using namespace std ;
struct quad {
   int cmd, i, p, r ;
} ;
int main() {
   int n, m, q ;
   cin >> n >> m >> q ;
   vector<vector<int> > dat(m) ;
   for (auto &v : dat) {
      int ts ;
      cin >> ts ;
      v.resize(ts) ;
      for (auto &u : v)
         cin >> u ;
   }
   vector<quad> cmds(q) ;
   for (auto &v : cmds) {
      cin >> v.cmd ;
      switch (v.cmd) {
case 1: cin >> v.i >> v.p ; v.i-- ; v.p-- ; break ;
case 2: cin >> v.p ; v.p-- ; break ;
case 3: cin >> v.i >> v.p >> v.r ; v.i-- ; v.p-- ; v.r-- ; break ;
      }
   }
   for (int i=0; i<q; i++)
      if (cmds[i].cmd == 2) {
         int add = cmds[i].p ;
         int j = i - 1 ;
         while (j >= 0 && (cmds[j].cmd != 1 ||
                cmds[j].p > add || cmds[j].p + (int)dat[cmds[j].i].size() <= add))
            j-- ;
         if (j < 0) {
            cout << 0 << endl ;
         } else {
            int di = cmds[j].i ;
            add -= cmds[j].p ;
            int inc = 0 ;
            for (int k=0; k<j; k++)
               if (cmds[k].cmd == 3 && cmds[k].i == di && cmds[k].p <= add &&
                   cmds[k].r >= add)
                  inc++ ;
            cout << (dat[di][add] + inc) % 256 << endl ;
         }
      }
}
