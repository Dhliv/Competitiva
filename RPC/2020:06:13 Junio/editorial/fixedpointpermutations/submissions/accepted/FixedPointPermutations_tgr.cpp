#include <iostream>
#include <vector>
using namespace std ;
typedef long long ll ;
const int MAXN = 64 ;
ll h[MAXN], fact[MAXN], g[MAXN][MAXN], c[MAXN][MAXN] ;
const ll INFTY = 2000000000000000000LL ;
ll overadd(ll a, ll b) {
   if (a >= INFTY || b >= INFTY || a+b >= INFTY)
      return INFTY ;
   return a + b ;
}
ll overmul(ll a, ll b) {
   if (a == 0 || b == 0)
      return 0 ;
   if (a >= INFTY || b >= INFTY || a >= INFTY/b)
      return INFTY ;
   return a * b ;
}
ll f(int n, int m, int p) {
   return overmul(c[m][p], g[n-p][m-p]) ;
}
void findperm(vector<int> &perm, int at, ll used, ll skip, int n, int p) {
   if (at == n) {
      if (skip != 0 || p != 0) {
         cout << "Failed." << endl ;
         exit(0) ;
      }
      return ;
   }
   for (int v=0; v<n; v++) {
      if ((used >> v) & 1)
         continue ;
      int pn = p - (v == at) ;
      if (pn < 0 || pn > n-at-1)
         continue ;
      int lft = 0 ;
      for (int j=at+1; j<n; j++)
         if (j != v && ((used >> j) & 1) == 0)
            lft++ ;
      if (pn > lft)
         continue ;
      ll cnt = f(n-at-1, lft, pn) ;
      if (cnt > skip) { // we have the right value
         perm[at] = v ;
         findperm(perm, at+1, used|(1LL<<v), skip, n, pn) ;
         return ;
      } else {  // go to the next value
         skip -= cnt ;
      }
   }
   cout << "Failed 2." << endl ;
}
int main(int argc, char *argv[]) {
   int n, p ;
   ll k ;
   cin >> n >> p >> k ;
   fact[0] = 1 ;
   for (int i=1; i<MAXN; i++)
      fact[i] = overmul(fact[i-1], i) ;
   c[0][0] = 1 ;
   for (int s=0; s<MAXN; s++) {
      c[s][0] = c[s][s] = 1 ;
      for (int a=1; a<s; a++)
         c[s][a] = overadd(c[s-1][a-1], c[s-1][a]) ;
   }
   h[0] = 1 ;
   h[1] = 0 ;
   for (int i=2; i<MAXN; i++)
      h[i] = overmul((i-1),overadd(h[i-1],h[i-2])) ;
   g[0][0] = 1 ;
   for (int a=1; a<MAXN; a++) {
      g[a][0] = fact[a] ;
      g[a][a] = h[a] ;
      for (int b=1; b<a; b++)
         g[a][b] = overadd(overmul(a-b,g[a-1][b]),overmul(b,g[a-1][b-1])) ;
   }
   k-- ; // use zero base
   if (k >= f(n, n, p)) {
      cout << -1 << endl ;
   } else {
      vector<int> perm(n) ;
      findperm(perm, 0, 0, k, n, p) ;
      for (int i=0; i<n; i++) {
         if (i)
            cout << " " ;
         cout << (perm[i]+1) ;
      }
      cout << endl ;
   }
}
