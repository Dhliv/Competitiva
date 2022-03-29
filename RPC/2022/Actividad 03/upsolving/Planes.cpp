#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
 
using namespace std;

struct aris{
  int x, y, cap;
};

int flights, uno = 1, zero = 0;
vector<vector<int> > g;
vector<aris> edges;
vector<int> seen;

int bfs(int &ori, int &dest){
  int x;
  FOR(i, 0, seen.size()) seen[i] = INF;
  seen[ori] = 0;
  deque<int> p;
  p.PB(ori);

  while(!p.empty()){
    x = p.F(); p.P_F();

    for(const auto &y: g[x]){
      const aris &e = edges[y];
      if(seen[e.y] != INF or e.cap == 0) continue;

      p.PB(e.y);
      seen[e.y] = seen[x] + 1;
    }
  }

  return seen[dest];
}

void bfs2(int &ori, vector<bool> &neoSeen, bool backward){
  int x;
  neoSeen[ori] = 1;
  deque<int> p;
  p.PB(ori);
  while(!p.empty()){
    x = p.F(); p.P_F();

    for(const auto &y: g[x]){
      const aris &e = edges[y];
      if(neoSeen[e.y] or e.cap == backward) continue;

      p.PB(e.y);
      neoSeen[e.y] = 1;
    }
  }
}

int dfs(int ori, int &dest, vector<int> &dp) {
  int flow = INF, y;

  for(int &i = dp[ori]; i < g[ori].size(); i++){
    y = g[ori][i];
    aris &e = edges[y];
    if(seen[ori] + 1 != seen[e.y] or e.cap == 0) continue;
    if(e.y == dest) {
      flights--;
      e.cap = 0;
      edges[y^1].cap = 1; // la arista contraria
      return 1;
    }else{
      flow = dfs(e.y, dest, dp);

      if(flow != INF){
        e.cap = 0;
        edges[y^1].cap = 1; // la arista contraria
        return flow;
      }
    }
  }

  return flow;
}

void addEdge(int &x, int &y){
  g[x].PB(edges.size());
  edges.PB({x, y, uno});

  g[y].PB(edges.size());
  edges.PB({y, x, zero});
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, s = 0, t; cin >> n >> m;
  t = 2*n + 1;
  flights = n - 1;
  g.assign(t + 1, vector<int> (0));
  seen.assign(t + 1, INF);

  FOR(i, 0, m){
    cin >> x >> y;
    y += n;
    addEdge(x, y);
  }

  for(int i = 1; i < n + 1; i++) addEdge(s, i);
  for(int i = n + 1; i < t; i++) addEdge(i, t);

  while(bfs(s, t) != INF){
    vector<int> dp(t + 1);
    while(dfs(s, t, dp) != INF){}
  }

  cout << flights << "\n";
  if(flights) {
    vector<bool> ini(t + 1), fin(t + 1);
    bfs2(s, fin, false);
    bfs2(t, ini, true);

    deque<int> ans;
    for(int i = 1; i < n + 1; i++) if(fin[i] or ini[i + n]) ans.PB(i);
    cout << ans.F();

    FOR(i, 1, ans.size()) cout << " " << ans[i];
    cout << "\n";
  }

  return 0;
}
