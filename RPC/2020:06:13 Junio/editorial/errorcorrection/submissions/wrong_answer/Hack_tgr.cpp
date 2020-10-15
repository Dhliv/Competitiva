#include <climits>
#include <sys/time.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std ;
double walltime() {
   struct timeval tv ;
   gettimeofday(&tv, 0) ;
   return tv.tv_sec + 0.000001 * tv.tv_usec ;
}
int bc(int v) {
   int r = 0 ;
   while (v) {
      r++ ;
      v &= v-1 ;
   }
   return r ;
}
int calcparity(const string &s) {
   int seen = 0 ;
   int p = 0 ;
   for (auto c : s) {
      c -= 'a' ;
      p += bc(((1<<c)-1) & seen) ;
      seen |= 1<<c ;
   }
   return p&1 ;
}
struct link {
   int i ;
   link *l, *r ;
} ;
void setup(vector<string> &w, map<string, int> &back, vector<vector<int> > &e) {
   int n = w.size() ;
   e.clear() ;
   e.resize(n) ;
   back.clear() ;
   for (int i=0; i<(int)w.size(); i++)
      back[w[i]] = i ;
   for (int i=0; i<(int)w.size(); i++) {
      string s = w[i] ;
      for (int j=0; j<(int)s.size(); j++)
         for (int k=0; k<j; k++) {
            swap(s[j], s[k]) ;
            auto it = back.find(s) ;
            if (it != back.end())
               e[i].push_back(it->second) ;
            swap(s[j], s[k]) ;
         }
   }
}
int main(int argc, char *argv[]) {
   srand48(time(0)) ;
   double start = walltime() ;
   int verbose = (argc > 1) ;
   int n ;
   cin >> n ;
   vector<string> w(n) ;
   for (auto &v : w)
      cin >> v ;
   int r = 0 ;
   map<string, int> back ;
   vector<vector<int> > e ;
   setup(w, back, e) ;
   int zerov = 0 ;
   for (int trial=0; walltime()-start < 0.9; trial++) {
      int wn = w[0].size() ;
      vector<link> heads(wn*(wn-1)/2+1) ;
      for (auto &v : heads) {
         v.i = -1 ;
         v.l = &v ;
         v.r = &v ;
      }
      vector<link> nodes(n) ;
      vector<int> cec(n) ;
      vector<char> ing(n), outg(n), unsure(n) ;
      for (auto &v : unsure)
         v = 1 ;
      for (int i=0; i<n; i++)
         cec[i] = e[i].size() ;
      for (int i=0; i<n; i++) {
         int ec = e[i].size() ;
         nodes[i].i = i ;
         nodes[i].l = &heads[ec] ;
         nodes[i].r = heads[ec].r ;
         heads[ec].r->l = &nodes[i] ;
         heads[ec].r = &nodes[i] ;
      }
      int toting = 0 ;
      while (1) {
         int at = 0 ;
         while (at < (int)heads.size() && heads[at].r == &heads[at])
            at++ ;
         if (at >= (int)heads.size() || (at >= 2 && trial == 0))
            break ;
         toting++ ;
         link *lnk = heads[at].r ;
         int s = lnk->i ;
 //  if (verbose) cout << "Including " << w[s] << " ec " << at << endl ;
         lnk->r->l = lnk->l ;
         lnk->l->r = lnk->r ;
         ing[s] = 1 ;
         unsure[s] = 0 ;
         for (auto b : e[s]) {
            cec[b]-- ;
            if (unsure[b]) {
// if (verbose) cout << "Excluding " << w[b] << endl ;
               unsure[b] = 0 ;
               outg[b] = 1 ;
               link *lnk = &nodes[b] ;
               lnk->r->l = lnk->l ;
               lnk->l->r = lnk->r ;
               outg[b] = 1 ;
               unsure[b] = 0 ;
               for (auto c : e[b]) {
                  if (unsure[c]) {
                     cec[c]-- ;
//   if (verbose) cout << "Decreasing " << w[c] << " to " << cec[c] << endl ;
                     link *lnk = &nodes[c] ;
                     lnk->r->l = lnk->l ;
                     lnk->l->r = lnk->r ;
                     lnk->r = heads[cec[c]].r ;
                     lnk->l = &heads[cec[c]] ;
                     heads[cec[c]].r->l = lnk ;
                     heads[cec[c]].r = lnk ;
                  }
               }
            }
         }
      }
      if (trial == 0) {
         r = toting ;
         zerov = toting ;
         vector<string> nw ;
         for (int i=0; i<n; i++)
            if (unsure[i])
               nw.push_back(w[i]) ;
         swap(nw, w) ;
         n = (int)w.size() ;
         if (n == 0)
            break ;
 if (verbose) cerr << "Now n is " << n << endl ;
         setup(w, back, e) ;
         int odd = 0 ;
         for (auto s : w)
            if (calcparity(s))
               odd++ ;
         r = max(r, zerov + odd) ;
         r = max(r, zerov + (int)w.size() - odd) ;
      } else {
         r = max(r, zerov + toting) ;
         for (int i=0; i<n; i++) {
            int j = i + (int)((n-i)*drand48()) ;
            swap(w[i], w[j]) ;
         }
         setup(w, back, e) ;
      }
   }
   cout << r << endl ;
}
