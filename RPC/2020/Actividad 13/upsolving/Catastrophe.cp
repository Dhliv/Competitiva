#include <bits/stdc++.h>
#define INF 1000000000
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

deque<deque<int> > cost;
deque<int> se;
int ft, maxi;

int bfs(int ori, int dest, deque<deque<int> > &grf){
  int x, y, c;
  FOR(i, 0, dest + 1) se[i] = INF;
  deque<int> q;
  q.PB(ori);
  se[ori] = 0;
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grf[x].size()){
      y = grf[x][i];
      c = se[x] + 1;
      
      if(se[y] == INF and cost[x][y] <= maxi){
        se[y] = c;
        q.PB(y);
      }
    }
  }
  
  return se[dest];
}

int dfs(int ori, int &dest, int mini, deque<deque<int> > &grf, deque<deque<int> > &flows){
  int y, flujo = INF;
  
  FOR(i, 0, grf[ori].size()){
    y = grf[ori][i];
    if(cost[ori][y] > maxi) continue;
    if(y == dest){
      flujo = min(mini, flows[ori][y]);
      ft += flujo;
      flows[ori][y] -= flujo;
      flows[y][ori] += flujo;
      if(flows[ori][y] == 0) grf[ori].erase(grf[ori].begin() + i);
      if(flows[y][ori] == flujo) grf[y].PB(ori);
      return flujo;
    }else if(se[ori] + 1 == se[y]){
      flujo = dfs(y, dest, min(mini, flows[ori][y]), grf, flows);
      
      if(flujo != INF){
        flows[ori][y] -= flujo;
        flows[y][ori] += flujo;
        if(flows[ori][y] == 0) grf[ori].erase(grf[ori].begin() + i);
        if(flows[y][ori] == flujo) grf[y].PB(ori);
        return flujo;
      }
    }
  }
  
  return flujo;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  int n, m, X, x, y, c, s, t, ax, bx;
  cin >> n >> m >> X;
  deque<int> p(n + 1), tal(n + 1);
  deque<deque<int> > grafo(2*n + 2), flows(2*n + 2, deque<int> (2*n + 2)), grf(n + 1);
  cost.resize(2*n + 2, deque<int> (2*n + 2, 0));
  se.resize(2*n + 2);
  s = 0;
  t = 2*n + 1;
  FOR(i, 1, n + 1) cin >> p[i];
  FOR(i, 1, n + 1) cin >> tal[i];
  
  FOR(i, 0, m){
    cin >> x >> y >> c;
    if(cost[x][y] == 0){
      grf[x].PB(y);
      grf[y].PB(x);
      cost[x][y] = c;
      cost[y][x] = c;
    }else cost[x][y] = cost[y][x] = min(cost[x][y], c);
  }
  
  FOR(i, 1, n + 1){
    if(p[i]) grafo[s].PB(i);
    flows[s][i] = p[i];
    grafo[i].PB(i + n);
    flows[i][i + n] = INF;
    if(tal[i]) grafo[i + n].PB(t);
    flows[i + n][t] = tal[i];
  }
  
  priority_queue<pair<int ,int> > q;
  FOR(i, 1, n + 1){
    deque<int> seen(n + 1, INF);
    deque<bool> v(n + 1);
    seen[i] = 0;
    q.push(MP(0, i));
    
    while(!q.empty()){
      x = q.top().s;
      q.pop();
      
      if(v[x]) continue;
      v[x] = 1;
      
      FOR(j, 0, grf[x].size()){
        y = grf[x][j];
        if(v[y]) continue;
        c = seen[x] + cost[x][y];
        
        if(seen[y] > c and c <= X){
          seen[y] = c;
          q.push(MP(-c, y));
        }
      }
    }
    
    FOR(j, 1, n + 1){
      if(seen[j] != INF){
        flows[i][j + n] = INF;
        grafo[i].PB(j + n);
      }
      cost[i][j + n] = seen[j];
    }
  }
  
  int low = 0, high = X, mid, mini;
  deque<deque<int> > cg, cf;
  ft = 0;
  maxi = X;
  cg = grafo;
  cf = flows;
  
  while(true){
    x = bfs(s, t, cg);
    //cout << x << ":";
    if(x == INF) break;
    while(true){
      y = dfs(s, t, INF, cg, cf);
      //cout << " " << y << "\n";
      if(y == INF) break;
    }
    //cout << "\n";
  }
  mini = ft;
  
  while(low <= high){
    mid = (low + high)/2;
    ft = 0;
    cg = grafo;
    
    FOR(i, 0, t + 1){
      FOR(j, 0, grafo[i].size()){
        x = grafo[i][j];
        cf[i][x] = flows[i][x];
        cf[x][i] = 0;
      }
    }
    
    maxi = mid;
    while(true){
      x = bfs(s, t, cg);
      if(x == INF) break;
      while(dfs(s, t, INF, cg, cf) != INF){}
    }
    
    if(ft == mini) high = mid - 1;
    else low = mid + 1;
  }
  
  cout << low << " " << mini << "\n";
  
  return 0;
}