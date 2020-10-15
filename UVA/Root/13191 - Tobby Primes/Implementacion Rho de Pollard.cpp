#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

ll pw(ll a, ll d, ll n){
  vector<ll> dp(64);
  dp[0] = a;
  ll res;
  
  FOR(i, 1, 64) dp[i] = (dp[i - 1]*dp[i - 1])%n;
  
  deque<int> pots;
  
  FOR(i, 0, 64){
    if(d & (ll)1 << i) pots.PB(i);
  }
  
  res = dp[pots.F()];
  pots.P_F();
  
  while(!pots.empty()){
    res = (res*dp[pots.F()])%n;
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
        x = (x*x)%n;
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

int main(){
  ll n, r = 0, x, m, d, cases;
  bool prm;
  cin >> cases;
  
  FOR(b, 0, cases){
    cin >> n;
    prm = prime(n);
    
    if(prm) cout << "Primo\n";
    else cout << "Compuesto\n";
  }
  
  return 0;
}
