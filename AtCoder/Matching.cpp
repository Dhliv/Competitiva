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
#define ld long double
#define MAX 21

using namespace std;

const ll MOD = 1000000007;

int able[MAX][MAX];
ll dp[MAX][1 << (MAX + 1)];
int n;

ll f(int i, int mask){
  if(i == n) return 1;
  ll &ans = dp[i][mask];
  if(ans != -1) return ans;

  ans = 0;
  FOR(j, 0, n){
    if(mask & (1 << j)) continue;
    if(able[i][j] == 0) continue;
    ans += f(i + 1, mask | (1 << j))%MOD;
    ans %= MOD;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, 0,n){
    FOR(j, 0, n) cin >> able[i][j];
  }

  memset(dp, -1, sizeof(dp));
  cout << f(0, 0) << "\n";

  return 0;
}