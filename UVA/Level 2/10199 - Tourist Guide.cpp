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

vector<bool> visited, marked;
vector<int> tin, low;
deque<int> artics;
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
            if (low[to] >= tin[v] && p!=-1 and !marked[v]){
              artics.PB(v);
              marked[v] = 1;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1 and !marked[v]){
      artics.PB(v);
      marked[v] = 1;
    }
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    marked.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs (i);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int id = 0;
  while(cin >> n, n){
    if(id++) cout << "\n";
    g.assign(n, {});
    string s;
    map<string, int> ids;
    map<int, string> names;

    FOR(i, 0, n){
      cin >> s;
      ids.insert(MP(s, i));
      names.insert(MP(i, s));
    }

    int m; cin >> m;
    string a, b;
    int x, y;
    FOR(i, 0, m){
      cin >> a >> b;
      x = ids[a]; y = ids[b];
      g[x].PB(y);
      g[y].PB(x);
    }

    find_cutpoints();

    deque<string> ans(artics.size());
    FOR(i, 0, artics.size()) ans[i] = names[artics[i]];
    sort(ans.begin(), ans.end());

    cout << "City map #" << id << ": " << ans.size() << " camera(s) found\n";
    FOR(i, 0, ans.size()) cout << ans[i] << "\n";
    deque<int> ax;
    ax.swap(artics);
  }

  return 0;
}