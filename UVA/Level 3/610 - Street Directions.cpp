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

int n; // number of nodes
vector<vector<int>> g; // adjacency list of graph

vector<bool> visited, marked;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;

        if(!marked[to]) cout << v << " " << to << "\n";
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                cout << to << " " << v << "\n";
        }
    }

    marked[v] = true;
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    marked.assign(n, false);
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

  int m, id = 1;

  while(cin >> n >> m, n + m){
    cout << id++ << "\n\n";
    n++;
    g.assign(n, {});
    FOR(i, 0, m){
      int x, y; cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
    }

    find_bridges();
    cout << "#\n";
  }

  return 0;
}