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
vector<int> tin, low;
deque<pair<int, int> > ans;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) ans.PB(MP(min(to, v), max(v, to)));
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, x, y;

  while(cin >> n >> m, n + m){
    g.assign(n, {});

    FOR(i, 0, m){
        cin >> x >> y;
        g[x].PB(y);
        g[y].PB(x);
    }

    find_bridges();

    sort(ans.begin(), ans.end());

    cout << ans.size();
    while(ans.size()){
        cout << " " << ans.F().f << " " << ans.F().s;
        ans.P_F();
    }
    cout << "\n";
  }

  return 0;
}