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

struct dt{
  int cost, pos;

  dt(){}
  dt(int pos, int cost) : cost(cost), pos(pos) {}
};

int n;
vector<vector<int> > p, cost;
vector<vector<dt> > nx;
vector<ll> dp;

ll f(int i){
  if(i == n) return 0;
  ll &ans = dp[i];
  if(ans != -1) return ans;

  ans = f(i + 1);
  FOR(j, 0, p[i].size()){
    if(nx[i][j].pos == -1) continue;
    ans = max(ans, f(nx[i][j].pos) - cost[i][j] + nx[i][j].cost);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, k, c; cin >> n;
  p.assign(n, {});
  nx.assign(n, {});
  cost.assign(n, {});
  dp.assign(n, -1);

  FOR(i, 0, n){
    cin >> m;
    FOR(j, 0, m){
      cin >> k >> c;
      p[i].PB(k);
      cost[i].PB(c);
    }
  }

  map<int, dt> mp;
  int pos;
  FORI(i, n - 1, 0){
    FOR(j, 0, p[i].size()){
      auto it = mp.find(p[i][j]);
      pos = -1;
      c = -1;
      if(it != mp.end()){
        pos = it->s.pos;
        c = it->s.cost;
      }

      nx[i].PB(dt(pos, c));
      mp[p[i][j]] = dt(i, cost[i][j]);
    }
  }

  cout << f(0) << "\n";

  return 0;
}