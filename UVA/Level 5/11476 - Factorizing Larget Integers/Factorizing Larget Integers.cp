#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

vector<int> a{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

long long mult(long long a, long long b, long long mod) {
    return ((__int128)a * b) % mod;
}

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

ll pw(ll a, ll d, ll n){
  vector<ll> dp(64);
  dp[0] = a;
  ll res;
  
  FOR(i, 1, 64) dp[i] = mult(dp[i - 1], dp[i - 1], n);
  
  deque<int> pots;
  
  FOR(i, 0, 64){
    if(d & (ll)1 << i) pots.PB(i);
  }
  
  res = dp[pots.F()]%n;
  pots.P_F();
  
  while(!pots.empty()){
    res = (mult(res, dp[pots.F()], n))%n;
    pots.P_F();
  }
  
  return res;
}

bool prime(ll n){
  ll r, x, m, d;
  bool out;
  r = 0;
  m = n - 1;
    
  while(m%2 == 0){
    m /= 2;
    r++;
  }
  d = m;
    
  FOR(i, 0, a.size()){
    x = pw(a[i], d, n);
    out = false;
    if(x == 1 or x == n - 1) continue;
    else{
      FOR(j, 0, r - 1){
        x = mult(x, x, n);
        if(x == n - 1){
          out = true;
          break;
        }
      }
    }
      
    if(out) continue;
    return false;
  }
  return true;
}

long long rho(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(x - y), n);
    }
    return g;
}

int main(){
  ll cases, n, lim = 1000000, cont, m;
  cin >> cases;
  
  vector<int> num(lim), prims;
  vector<bool> seen(lim, 0);
  
  FOR(i, 2, lim){
    if(!seen[i]){
      seen[i] = true;
      prims.PB(i);
      
      for(int j = 2*i; j < lim; j += i) seen[j] = true;
    }
  }
  
  FOR(a, 0, cases){
    cin >> n;
    vector<pair<ll, int> > ans;
    cout << n << " = ";
    
    for(int i = 0; i < prims.size() and n > 1; i++){
      if(n%prims[i] == 0){
        cont = 0;
        while(n%prims[i] == 0){
          n /= prims[i];
          cont++;
        }
        
        ans.PB(MP(prims[i], cont));
      }
    }
    
    if(n > 1){
      if(prime(n)) ans.PB(MP(n, 1));
      else{
        m = rho(n);
        int aux = n/m;
        if(aux == m) ans.PB(MP(m, 2));
        else{
          if(m < aux){
            ans.PB(MP(m, 1));
            ans.PB(MP(aux, 1));
          }else{
            ans.PB(MP(aux, 1));
            ans.PB(MP(m, 1));
          }
        }
      }
    }
    
    FOR(i, 0, ans.size() - 1){
      if(ans[i].s > 1) cout << ans[i].f << "^" << ans[i].s << " * ";
      else cout << ans[i].f << " * ";
    }
    
    n = ans.size() - 1;
    if(ans[n].s > 1) cout << ans[n].f << "^" << ans[n].s << "\n";
    else cout << ans[n].f << "\n";
  }
  
  return 0;
}