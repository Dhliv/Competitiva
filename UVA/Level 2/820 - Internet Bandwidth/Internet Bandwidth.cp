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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int ft;

int bfs(vector<vector<int> > &grafo, int ori, int dest, int n){
  int x, y;
  vector<int> seen(n, INF);
  seen[ori] = 0;
  deque<int> q;
  q.PB(ori);
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      if(seen[y] > seen[x] + 1){
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return seen[dest];
}

int dfs(vector<vector<int> > &grafo, vector<vector<int> > &flows, int ori, int &dest, int &path, int act, int mini){
  int acum = act + 1, flujo = INF, y;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(acum == path and y != dest) continue;
    else if(acum == path){
      flujo = min(mini, flows[ori][y]);
      ft += flujo;
      
      flows[ori][y] -= flujo;
      //flows[y][ori] += flujo;
      //grafo[y].PB(ori);
        
      if(0 == flows[ori][y]) grafo[ori].erase(grafo[ori].begin() + i);
      return flujo;
    }else{
      flujo = dfs(grafo, flows, y, dest, path, acum, min(mini, flows[ori][y]));
      
      if(flujo != INF){
        flows[ori][y] -= flujo;
        //flows[y][ori] += flujo;
        //grafo[y].PB(ori);
        if(0 == flows[ori][y]) grafo[ori].erase(grafo[ori].begin() + i);
        return flujo;
      }
    }
  }
  
  return flujo;
}

int main(){
  int n, x, y, f, cont = 1, s, t, m, mini;
  
  while(cin >> n, n){
    vector<vector<int> > grafo(n + 1), flows(n + 1, vector<int> (n + 1)), inside(n + 1, vector<int> (n + 1));
    cin >> s >> t >> m;
    
    FOR(i, 0, m){
      cin >> x >> y >> f;
      if(inside[x][y]){
        flows[x][y] += f;
        flows[y][x] += f;
      }else{
        inside[x][y] = 1;
        inside[y][x] = 1;
        flows[x][y] += f;
        flows[y][x] += f;
        grafo[x].PB(y);
        grafo[y].PB(x);
      }
    }
    
    ft = 0;
    
    while(true){
      mini = bfs(grafo, s, t, n + 1);
      
      if(mini == INF) break;
      else{
        while(dfs(grafo, flows, s, t, mini, 0, INF) != INF){}
      }
    }
    
    cout << "Network " << cont++ << "\n";
    cout << "The bandwidth is " << ft << ".\n\n";
  }
  
  return 0;
}