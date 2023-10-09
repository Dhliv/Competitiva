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

int farthestPoint(int ori, vector<vector<int> > &graph){
  vector<int> seen(graph.size(), INF);
  deque<int> q; q.PB(ori);
  seen[ori] = 0;
  int x;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y: graph[x]){
      if(seen[y] != INF) continue;
      seen[y] = seen[x] + 1;
      q.PB(y);
    }
  }

  int maxi = 0, node = ori;
  FOR(i, 1, graph.size()){
    if(seen[i] == INF or seen[i] <= maxi) continue;
    maxi = seen[i];
    node = i;
  }

  return node;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int m, x, y; cin >> n >> m;
  n++;
  g.assign(n, {});
  map<pair<int, int>, int> edges;


  FOR(i, 0, m){
    cin >> x >> y;
    if(x > y) swap(x, y);

    auto it = edges.find(MP(x, y));
    if(it != edges.end()){
      it->s++;
      continue;
    }

    g[x].PB(y);
    g[y].PB(x);
    edges.insert(MP(MP(x, y), 1));
  }

  find_bridges();

  vector<int> p(n), s(n, 1), ids(n);
  FOR(i, 1, n) ids[tin[i]] = i;
  FOR(i, 1, n) p[i] = i;

  FOR(i, 1, n) merge(tin[i], low[i], p, s);

  int fx, fy;
  deque<pair<int, int> > realBridges;
  FOR(i, 0, bridges.size()){
    x = bridges[i].f;
    y = bridges[i].s;
    if(x > y) swap(x, y);

    fx = find(tin[x], p);
    fy = find(tin[y], p);
    if(edges[MP(x, y)] > 1){
      merge(fx, fy, p, s);
      continue;
    }

    realBridges.PB(bridges[i]);
  }

  vector<vector<int> > ng(n);
  FOR(i, 0, realBridges.size()){
    x = realBridges[i].f;
    y = realBridges[i].s;
    fx = find(tin[x], p);
    fy = find(tin[y], p);

    if(fx == fy) continue;
    ng[fx].PB(fy);
    ng[fy].PB(fx);
  }

  int aa = 1, bb, raa, rbb;
  FOR(i, 1, n){
    if(ng[i].size()){
      aa = farthestPoint(i, ng);
      break;
    }
  }
  bb = farthestPoint(aa, ng);
  raa = ids[aa]; rbb = ids[bb];

  cout << raa << " " << rbb << "\n";

  return 0;
}