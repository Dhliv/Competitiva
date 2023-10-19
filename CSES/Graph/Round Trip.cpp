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

const ld EPSILON = 0.0000000001;

int n;
vector<vector<int>> g;
vector<bool> v;
deque<int> route;
bool able = false;

void dfs(int ori, int fat, int &ORI){
  v[ori] = 1;
  route.PB(ori);

  for(const int &y: g[ori]){
    if(able) return;
    if(y == ori or y == fat) continue;
    if(v[y]){
      able = true;
      route.PB(y);
      ORI = y;
      return;
    }

    dfs(y, ori, ORI);
  }

  if(able) return;
  route.P_B();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m; cin >> n >> m;
  g.assign(n + 1, {});
  v.assign(n + 1, {});
  int x, y;
  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  int last = -1;
  FOR(i, 1, n + 1){
    if(v[i]) continue;
    dfs(i, -1, last);
    if(last != -1) break;
  }

  if(able){
    while(route.F() != last) route.P_F();
    cout << route.size() << "\n";
    FOR(i, 0, route.size()) cout << route[i] << " ";
    cout << "\n";
  }else cout << "IMPOSSIBLE\n";

  return 0;
}