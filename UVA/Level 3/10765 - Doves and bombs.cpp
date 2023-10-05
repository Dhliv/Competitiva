#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

int n;
vector<vector<int>> g;

vector<bool> visited;
vector<int> tin, low, artics;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1){
              artics[v]++;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
      artics[v]++;
    }
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    artics.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs (i);
    }
}

bool comp(pair<int, int> &a, pair<int, int> &b){
  if(a.s == b.s) return a.f < b.f;
  return a.s > b.s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cand;
  int x, y;

  while(cin >> n >> cand, n + cand){
    g.assign(n, {});

    while(cin >> x >> y, x != -1){
      g[x].PB(y);
      g[y].PB(x);
    }

    find_cutpoints();

    deque<pair<int, int> > ans(n);
    FOR(i, 0, n){
      ans[i] = MP(i, artics[i]);
    }

    sort(ans.begin(), ans.end(), comp);

    FOR(i, 0, cand) cout << ans[i].f << " " << ans[i].s << "\n";
    cout << "\n";
  }

  return 0;
}