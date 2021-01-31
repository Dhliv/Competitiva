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

vector<int> se;

int bfs(int &ori, int &dest, vector<vector<int> > &grafo){
  int x, y;
  FOR(i, 0, grafo.size()) se[i] = INF;
  deque<int> q;
  se[ori] = 0;
  q.PB(ori);
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      if(se[y] == INF){
        se[y] = se[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return se[dest];
}

int dfs(int ori, int &dest, vector<vector<int> > &grafo, vector<vector<int> > &flows){
  int y, flujo = INF;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(y == dest){
      flujo = 1;
      flows[ori][y] -= flujo;
      flows[y][ori] += flujo;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == flujo) grafo[y].PB(ori);
      return flujo;
    }else if(se[ori] + 1 == se[y]){
      flujo = dfs(y, dest, grafo, flows);
      
      if(flujo != INF){
        flows[ori][y] -= flujo;
        flows[y][ori] += flujo;
        if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
        if(flows[y][ori] == flujo) grafo[y].PB(ori);
        return flujo;
      }
    }
  }
  
  return flujo;
}

int main(){
  ios_base::sync_with_stdio(false);
  int cases, s, t, n, n1, x, y, k;
  string ent;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n1;
    vector<vector<string> > names(n1, vector<string> (26));
    n = 2*n1 + 2;
    vector<vector<int> > grafo(n), flows(n, vector<int> (n));
    se.resize(n);
    s = n - 2;
    t = n - 1;
    
    FOR(i, 0, n1){
      cin >> k;
      grafo[s].PB(i);
      flows[s][i] = 1;
      
      FOR(j, 0, k){
        cin >> ent;
        x = tolower(ent[0]) - 'a';
        ent[0] = toupper(ent[0]);
        FOR(l, 1, ent.size()) ent[l] = tolower(ent[l]);
        names[i][x] = ent;
        
        if(x < n1){
          x += n1;
          grafo[i].PB(x);
          flows[i][x] = 1;
        }
      }
    }
    
    FOR(i, n1, s){
      grafo[i].PB(t);
      flows[i][t] = 1;
    }
    
    while(bfs(s, t, grafo) != INF) while(dfs(s, t, grafo, flows) != INF){}
    
    cout << "Case #" << ab + 1 << ":\n";
    FOR(i, n1, s){
      FOR(j, 0, grafo[i].size()){
        y = grafo[i][j];
        if(y < n1){
          cout << names[y][i - n1] << "\n";
          break;
        }
      }
    }
  }
  
  return 0;
}