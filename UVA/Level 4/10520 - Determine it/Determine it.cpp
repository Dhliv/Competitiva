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

ll recu(vector<vector<ll> > &dp, int n, int i, int j){
  if(dp[i][j] != MINF) return dp[i][j];
  
  if(i < j){
    ll ans = 0;
    FOR(a, i, j) ans = max(ans, recu(dp, n, i, a) + recu(dp, n, a + 1, j));
    dp[i][j] = ans;
    return ans;
  }else{
    ll l = 0, r = 0;
    
    if(i < n){
      FOR(a, i + 1, n + 1) l = max(l, recu(dp, n, a, 1) + recu(dp, n, a, j));
    }
    
    if(j > 1){
      FOR(a, 1, j) r = max(r, recu(dp, n, i, a) + recu(dp, n, n, a));
    }
    
    dp[i][j] = l + r;
    return dp[i][j];
  }
}

int main(){
  int n;
  
  while(cin >> n){
    vector<vector<ll> > dp(n + 1, vector<ll> (n + 1, MINF));
    cin >> dp[n][1];
    
    cout << recu(dp, n, 1, n) << "\n";
  }
  
  return 0;
}
