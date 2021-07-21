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

const int mod = 1000000007;
ll n, dp[101][100000], ns[100000];
int m;

ll f(int bef, int i){
  if(i == n) return 1;
  ll &ans = dp[bef][i];
  if(ans != -1) return ans;
  if(ns[i] != 0){
    if(abs(bef - ns[i]) > 1) return ans = 0;
    return ans = f(ns[i], i + 1);
  }

  ans = 0;
  int l = max(1, bef - 1), r = min(m, bef + 1) + 1;
  FOR(j, l, r) ans += f(j, i + 1);
  ans %= mod;

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  ll ans;
  memset(dp, -1, sizeof(dp));

  FOR(i, 0, n) cin >> ns[i];

  ans = 0;
  
  if(ns[0] == 0){
    FOR(i, 1, m + 1) ans += f(i, 1);
  }else ans += f(ns[0], 1);
  ans %= mod;
  cout << ans << "\n";

  return 0;
}