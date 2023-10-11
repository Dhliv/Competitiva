#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.000000001;

int f(int x, bool used, vector<vector<int> > &g, vector<int> &s, vector<vector<int> > &dp){
  int &ans = dp[x][used];
  if(ans != -1) return ans;

  ans = s[x];
  for(const int &y: g[x]){
    if(s[x] >= s[y] and used) continue;
    ans = min(ans, f(y, used or s[x] >= s[y], g, s, dp));
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, m, x, y;

  while(t--){
    cin >> n >> m;
    n++;
    vector<vector<int> > g(n);
    FOR(i, 0, m){
      cin >> x >> y;
      g[x].PB(y);
    }

    vector<int> seen(n, INF);
    seen[1] = 0;
    deque<int> q(1, 1);

    while(!q.empty()){
      x = q.F();
      q.P_F();

      for(const int &y : g[x]){
        if(seen[y] != INF) continue;
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }

    vector<vector<int> > dp(n, vector<int> (2, -1));
    dp[1][0] = dp[1][1] = 0;
    FOR(i, 1, n) cout << f(i, 0, g, seen, dp) << " ";
    cout << "\n";
  }

  return 0;
}