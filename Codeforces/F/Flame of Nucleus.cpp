#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

using namespace std;

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

int dfs(int ori, int &target, int min_flow){
  int flow = INF, y;

  for(auto &e_id: grafo[ori]){
    auto &e = edges[e_id];
    y = e.y;

    if(sn[y] != 1 + sn[ori]) continue;
    if(e.flow <= 0) continue;

    if(y == target){
      flow = min(min_flow, e.flow);
      ans += flow;
      edges[e_id].flow -= flow;
      edges[e_id^1].flow += flow;
      return flow;
    }

    flow = dfs(y, target, min(min_flow, e.flow));

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

  int n, m, l, x, y, z, s, t, d;

  while(cin >> n >> m >> l){
    vector<vector<pair<int, int> > > g(n + 1);
    s = 0;
    t = 2*n + 1;
    ans = 0;

    FOR(i, 0, m){
      cin >> x >> y >> d;
      g[x].PB(MP(y, d));
      g[y].PB(MP(x, d));
    }

    vector<int> pob(n + 1), shelter(n + 1);
    FOR(i, 1, n + 1) cin >> pob[i];
    FOR(i, 1, n + 1) cin >> shelter[i];

    vector<vector<int> > seen(n + 1, vector<int> (n + 1, INF));
    vector<vector<bool> > visto(n + 1, vector<bool> (n + 1, false));
    FOR(i, 1, n + 1){
      seen[i][i] = 0;
      priority_queue<pair<int, int> > pq;
      pq.push(MP(0, i));

      while(!pq.empty()){
        x = pq.top().s; pq.pop();

        if(visto[i][x]) continue;
        visto[i][x] = 1;

        for(auto &y: g[x]){
          z = y.f;
          d = y.s + seen[i][x];

          if(visto[i][z]) continue;
          if(d >= l) continue;
          if(seen[i][z] <= d) continue;

          seen[i][z] = d;
          pq.push(MP(-d, z));
        }
      }
    }

    edges.assign(0, {});
    grafo.assign(t + 1, {});
    sn.assign(t + 1, INF);
    const int MAX = 1000002;

    FOR(i, 1, n + 1){
      addEdge(s, i, pob[i]);
      FOR(j, 1, n + 1){
        if(seen[i][j] == INF) continue;
        addEdge(i, j + n, MAX);
      }
      addEdge(i + n, t, shelter[i]);
    }

    while(bfs(s, t) != INF){
      while(dfs(s, t, INF) != INF){}
    }

    cout << ans << "\n";
  }

  return 0;
}