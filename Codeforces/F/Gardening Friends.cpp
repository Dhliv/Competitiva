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

const ld EPSILON = 0.0000001;

int bfs(int ori, vector<ll> &s, vector<vector<int> > &g){
  int x, nd = -1, maxi = 0;
  deque<int> q(1, ori);
  s[ori] = 0;

  while(!q.empty()){
    x = q.F(); q.P_F();

    for(const int &y: g[x]){
      if(s[y] != INF) continue;
      s[y] = 1 + s[x];
      if(s[y] > maxi){
        maxi = s[y];
        nd = y;
      }
      q.PB(y);
    }
  }

  return nd;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, k, c;

  while(t--){
    cin >> n >> k >> c;
    int x, y;

    vector<vector<int> > g(n + 1);
    FOR(i, 0, n - 1){
      cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
    }

    vector<ll> s(n + 1, INF), f1(n + 1, INF), f2(n + 1, INF);
    x = bfs(1, s, g);
    x = bfs(x, f1, g);
    x = bfs(x, f2, g);

    ll ans = 0, ax;
    FOR(i, 1, n + 1){
      ax = k*max(f1[i], f2[i]) - c*s[i];
      ans = max(ax, ans);
    }

    cout << ans << "\n";
  }
 
  return 0;
}