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