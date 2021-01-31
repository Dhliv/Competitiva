#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
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
 
using namespace std;

int mod = 1000000000, d[100];
ll uno = 1;

int f(int n, ll e){
  ll dp[63], ans;
  dp[0] = n;
  FOR(i, 1, 63) dp[i] = (dp[i - 1]*dp[i - 1] + mod)%mod;
  
  ans = 1;
  FOR(i, 0, 63){
    if(e & (uno << i)) ans = (ans*dp[i] + mod)%mod;
  }
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int cases, k, q;
  ll e, ex;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> k >> q;
    FOR(i, 0, k) cin >> d[i];
    
    FOR(i, 0, q){
      cin >> e;
      ex = e/k + 1;
      cout << f(d[e%k], ex) << "\n";
    }
  }
  
  return 0;
}