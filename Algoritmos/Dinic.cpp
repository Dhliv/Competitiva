vector<int> s;

int bfs(int &ori, int &dest, vector<vector<int> > &grafo, vector<vector<int> > &flows){
  int x, n = grafo.size();
  FOR(i, 0, n) s[i] = INF;
  
  deque<int> q;
  q.PB(ori);
  s[ori] = 0;
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    for(auto y: grafo[x]){
      if(s[y] != INF or flows[x][y] == 0) continue; // Edge already seen or Edge doesn't exists.
      
      s[y] = s[x] + 1;
      q.PB(y);
    }
  }
  
  return s[dest];
}

int dfs(int ori, int &dest, int minimo, vector<vector<int> > &grafo, vector<vector<int> > &flows){
  int flow = INF, c = s[ori] + 1;
  
  for(auto y: grafo[ori]){
    if(flows[ori][y] != 0){ // Edge exists.
      if(y == dest){
        flow = min(flows[ori][dest], minimo);
        
        flows[ori][y] -= flow;
        flows[y][ori] += flow;
        return flow;
      }else if(c == s[y]){
        flow = dfs(y, dest, min(flows[ori][y], minimo), grafo, flows);
        
        if(flow != INF){
          flows[ori][y] -= flow;
          flows[y][ori] += flow;
          return flow;
        }
      }
    }
  }
  
  return flow;
}