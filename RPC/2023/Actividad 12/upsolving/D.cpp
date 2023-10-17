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

struct edge{
  int x, y, flow;
};

int ans;
vector<edge> edges;
vector<vector<int> > grafo;
vector<int> sn;

void addEdge(int x, int y, int flow){
  grafo[x].PB(edges.size());
  edges.PB({x, y, flow});

  grafo[y].PB(edges.size());
  edges.PB({y, x, 0});
}

int bfs(int &ori, int &target){
  int x = ori, y, flow;

  FOR(i, 0, target + 1) sn[i] = INF;

  sn[x] = 0;
  deque<int> q(1, x);

  while(!q.empty()){
    x = q.F(); q.P_F();

    for(auto &e: grafo[x]){
      auto &edge = edges[e];
      y = edge.y;
      flow = edge.flow;

      if(flow <= 0) continue;
      if(sn[y] != INF) continue;
      sn[y] = sn[x] + 1;
      q.PB(y);
    }
  }

  return sn[target];
}

int dfs(int ori, int &target, vector<int> &dp){
  int flow = INF, y, e_id;

  for(int &pos = dp[ori]; pos < grafo[ori].size(); pos++){
    e_id = grafo[ori][pos];
    auto &e = edges[e_id];
    y = e.y;

    if(sn[y] != 1 + sn[ori]) continue;
    if(e.flow <= 0) continue;

    if(y == target){
      flow = 1;
      ans++;
      edges[e_id].flow -= flow;
      edges[e_id^1].flow += flow;
      return flow;
    }

    flow = dfs(y, target, dp);

    if(flow != INF){
      edges[e_id].flow -= flow;
      edges[e_id^1].flow += flow;
      return flow;
    }
  }

  return flow;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int MAXR = 100;
  int n, r;
  cin >> n >> r;
  int rn = 2*n;

  vector<vector<int> > p(r, vector<int> (rn));
  vector<vector<int> > valid(rn, vector<int> (rn));

  FOR(i, 0, r){
    FOR(j, 0, rn){
      cin >> p[i][j].val;
      p[i][j].pos = j;
    }
  }

  bitset<MAXR> ALLONE;
  FOR(i, 0, r) ALLONE[i] = 1;

  unordered_map<bitset<MAXR>, vector<int>> mp; 
  FOR(j, 0, rn){
    bitset<MAXR> skills;
    FOR(i, 0, r) skills[i] = p[i][j].val > n;
    mp[skills].PB(j);
  }


  for(auto i = mp.begin(); i != mp.end(); i++){
    bitset<MAXR> a = i->first;
    bitset<MAXR> comp = a ^ ALLONE;
    for(int j = 0 ; j < min(mp[comp].size(), i->second.size()) ; ++j){
      valid[min(mp[comp][j], i->second[j])][max(mp[comp][j], i->second[j])] = true;
    }
  }

  int nodes = 2 + 2*rn;
  int t = nodes - 1;
  int s = 0;
  grafo.assign(nodes, {});
  sn.assign(nodes, {});
  FOR(i, 1, rn + 1){
    addEdge(s, i, 1);
    addEdge(i + rn, t, 1);
  }

  FOR(i, 0, rn){
    FOR(j, i + 1, rn){
      if(!valid[i][j]) continue;
      addEdge(i + 1, j + rn + 1, 1);
    }
  }

  ans = 0;
  while(bfs(s, t) != INF){
    vector<int> dp(nodes);
    while(dfs(s, t, dp) != INF) {}
  }

  if(ans == n) cout << "possible\n";
  else cout << "impossible\n";

  return 0;
}