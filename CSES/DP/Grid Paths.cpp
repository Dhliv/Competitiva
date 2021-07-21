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

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  const int mod = 1000000007;
  vector<vector<int> > dp(2, vector<int> (n));
  vector<string> d(n);
  vector<int> o(n);
  
  FOR(i, 0, n) cin >> d[i];

  dp[0][0] = d[0][0] == '*' ? 0 : 1;

  FOR(i, 1, n) if(d[0][i] != '*') dp[0][i] += dp[0][i - 1];

  FOR(i, 1, n){
    FOR(j, 0, n){
      if(d[i][j] != '*'){
        dp[1][j] = dp[0][j];
        if(j > 0) dp[1][j] += dp[1][j - 1];
        dp[1][j] %= mod;
      }else dp[1][j] = 0;
    }
    dp[0].swap(dp[1]);
  }

  cout << dp[0][n - 1]%mod << "\n";

  return 0;
}