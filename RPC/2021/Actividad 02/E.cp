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

ll dp[505][505][11], d[500][500], p[500][500], r, c, n;

ll f(int i, int j, int k){
  if(k > n) return INF;
  if(j == c and k == n) return 0;
  if(j == c) return INF;
  if(d[i][j] == -1) return INF;
  ll &ans = dp[i][j][k];
  if(ans != -1) return ans;
  
  ans = INF;
  if(i > 0) ans = min(ans, d[i][j] + f(i - 1, j + 1, k + p[i][j]));
  if(i + 1 < r) ans = min(ans, d[i][j] + f(i + 1, j + 1, k + p[i][j]));
  ans = min(ans, d[i][j] + f(i, j + 1, k + p[i][j]));
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  int x, a, b, g, e;
  ll ans;
  cin >> r >> c >> n;
  
  memset(dp, -1, sizeof(dp));
  
  FOR(i, 0, r){
    FOR(j, 0, c){
      cin >> d[i][j];
      p[i][j] = 0;
    }
  }
  
  FOR(i, 1, r - 1){
    FOR(j, 1, c - 1){
      if(d[i][j] == -1) continue;
      x = d[i][j];
      a = d[i][j - 1];
      b = d[i][j + 1];
      g = d[i - 1][j];
      e = d[i + 1][j];
      if(a == -1 or b == -1 or g == -1 or e == -1) continue;
      if(x > a and x > b and x < g and x < e) p[i][j] = 1;
    }
  }
  
  ans = INF;
  FOR(i, 0, r){
    if(d[i][0] == -1) continue;
    ans = min(ans, f(i, 0, 0));
  }
  
  if(ans != INF) cout << ans << "\n";
  else cout << "impossible\n";
  
  return 0;
}