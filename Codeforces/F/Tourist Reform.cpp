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
deque<pair<int, int> > bridges;
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
            if (low[to] > tin[v]) bridges.PB(MP(v, to));
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

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<int> &p, vector<int> &s){
  int fa = find(a, p), fb = find(b, p);
  if(fa == fb) return;

  if(s[fa] > s[fb]) swap(fa, fb);
  p[fa] = fb;
  s[fb] += s[fa];
}

void dfs(int x, int p, int &group, deque<pair<int, int> > &ans, vector<int> &vis, vector<int> &exp, vector<int> &fat){
  vis[x] = 1;

  for(const int &y: g[x]){
    if(find(tin[y], fat) != group or y == p or exp[y]) continue;
    ans.PB(MP(x, y));
    if(vis[y]) continue;
    dfs(y, x, group, ans, vis, exp, fat);
  }

  exp[x] = 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, x, y; cin >> n >> m;
  n++;
  g.assign(n, {});

  vector<pair<int, int> > edges(m);
  FOR(i, 0, m){
    cin >> x >> y;
    edges[i] = MP(x, y);
    g[x].PB(y);
    g[y].PB(x);
  }

  find_bridges();

  vector<int> p(n), s(n, 1), ids(n);
  FOR(i, 1, n) ids[tin[i]] = i;
  FOR(i, 1, n) p[i] = i;
  FOR(i, 1, n) merge(tin[i], low[i], p, s);

  int a, maxi = 0;
  FOR(i, 1, n){
    if(i != find(i, p)) continue;
    if(s[i] > maxi){
      maxi = s[i];
      a = ids[i];
    }
  }

  cout << maxi << "\n";

  int fx, fy;
  map<pair<int, int>, pair<int, int> > realBridges;
  vector<vector<int> > ng(n);
  FOR(i, 0, bridges.size()){
    x = bridges[i].f; fx = ids[find(tin[x], p)];
    y = bridges[i].s; fy = ids[find(tin[y], p)];
    ng[fx].PB(fy);
    ng[fy].PB(fx);
    realBridges.insert(MP(MP(fx, fy), MP(x, y)));
    realBridges.insert(MP(MP(fy, fx), MP(y, x)));
  }

  deque<pair<int, int> > ans;

  deque<int> q(1, a);
  vector<int> seen(n, INF); seen[a] = 0;
  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y: ng[x]){
      if(seen[y] != INF) continue;
      seen[y] = 0;
      ans.PB(realBridges[MP(y, x)]);
      q.PB(y);
    }
  }

  vector<int> v(n), e(n);
  int group;
  FOR(i, 1, n){
    if(i != find(i, p)) continue;
    group = find(i, p);
    dfs(ids[i], -1, group, ans, v, e, p);
  }

  set<pair<int, int> > resp;
  FOR(i, 0, ans.size()) resp.insert(ans[i]);

  FOR(i, 0, m){
    if(resp.find(edges[i]) != resp.end()) cout << edges[i].f << " " << edges[i].s << "\n";
    else cout << edges[i].s << " " << edges[i].f << "\n";
  }

  return 0;
}