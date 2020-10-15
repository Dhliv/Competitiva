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

int main(){
  int b, p, mod, res;
  
  while(cin >> b >> p >> mod){
    vector<ll> dp(64);
    deque<int> q;
    dp[0] = b%mod;
    
    if(p == 0) cout << 1%mod << "\n";
    else{
      FOR(i, 1, 64) dp[i] = (dp[i - 1]*dp[i - 1])%mod;
      
      FOR(i, 0, 32) if(p & ((long long)1 << i)) q.PB(i);
      
      res = dp[q.F()];
      q.P_F();
      
      while(!q.empty()){
        res = (res*dp[q.F()])%mod;
        q.P_F();
      }
      
      cout << res << "\n";
    }
  }
  
  return 0;
}
