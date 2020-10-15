#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
const ll INF = 2'000'000'000'000'000'000LL ;
ll add(ll a, ll b) {
   ll c = a + b ;
   if (c >= INF)
      return INF ;
   return c ;
}
ll mul(ll a, ll b) {
   if (b > 0 && a > INF / b)
      return INF ;
   return a * b ;
}
const int MAX = 128 ;
ll c[MAX][MAX], f[MAX], g[MAX][MAX] ;
ll g3(ll n, ll m, ll x) {
   return mul(c[x][m], g[n-m][x-m]) ;
}
int main(int argc, char *argv[]) {
   f[0] = 1 ;
   for (int i=1; i<MAX; i++)
      f[i] = mul(f[i-1], i) ;
   for (int i=0; i<MAX; i++) {
      c[i][0] = c[i][i] = 1 ;
      for (int j=1; j<i; j++)
         c[i][j] = add(c[i-1][j-1], c[i-1][j]) ;
   }
   for (int i=0; i<MAX; i++) {
      g[i][0] = f[i] ;
      g[i][1] = mul(i-1, g[i-1][0]) ;
      for (int j=2; j<=i; j++)
         g[i][j] = add(mul(j-1, g[i-1][j-2]), mul(i-j, g[i-1][j-1])) ;
   }
   ll n, p, k ;
   cin >> n >> p >> k ;
   vector<char> used(n) ;
   ll matchable = n ;
   ll thiscnt = 0 ;
   k-- ;
   if (g3(n, p, n) <= k)
      cout << -1 ;
   else
      for (int pos=0; pos<n; pos++) {
         matchable -= !used[pos] ;
         for (int dig=0; dig<n; dig++) {
            if (used[dig])
               continue ;
            if (p == 0 && dig == pos)
               continue ; // no more matches available
            thiscnt = g3(n-pos-1, p-(dig==pos), matchable-(dig>pos)) ;
            if (thiscnt > k) {
               if (pos)
                  cout << " " ;
               cout << (dig + 1) ;
               if (dig > pos)
                  matchable-- ;
               if (dig == pos)
                  p-- ;
               used[dig]++ ;
               break ;
            } else
               k -= thiscnt ;
         }
      }
   cout << endl ;
}
