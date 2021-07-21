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

  int n, x, dp[1000001], c[100];
  const int mod = 1000000007;
  cin >> n >> x;
  FOR(i, 0, n) cin >> c[i];

  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  FOR(i, 0, n){
    FOR(j, c[i], x + 1){
      dp[j] += dp[j - c[i]];
      dp[j] %= mod;
    }
  }

  cout << dp[x] << "\n";

  return 0;
}