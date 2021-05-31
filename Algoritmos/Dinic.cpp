vector<int> s;

int bfs(int &ori, int &dest, vector<vector<int> > &grafo){
  int x, y, n = grafo.size();
  FOR(i, 0, n) s[i] = INF;
  
  deque<int> q;
  q.PB(ori);
  s[ori] = 0;
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      
      if(s[y] == INF){
        s[y] = s[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return s[dest];
}

int dfs(int ori, int &dest, int minimo, vector<vector<int> > &grafo, vector<vector<int> > &flows){
  int y, flow = INF, c = s[ori] + 1;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(y == dest){
      flow = min(flows[ori][dest], minimo);
      
      flows[ori][y] -= flow;
      flows[y][ori] += flow;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == flow) grafo[y].PB(ori);
    }else if(c == s[y]){
      flow = dfs(y, dest, min(flows[ori][y], minimo), grafo, flows);
      
      if(flow != INF){
        flows[ori][y] -= flow;
        flows[y][ori] += flow;
        if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
        if(flows[y][ori] == flow) grafo[y].PB(ori);
        return flow;
      }
    }
  }
  
  return flow;
}