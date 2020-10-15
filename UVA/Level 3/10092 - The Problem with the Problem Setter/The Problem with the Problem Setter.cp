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

int bfs(vector<vector<int> > &grafo, int s, int t){
  int x, y;
  vector<int> seen(grafo.size(), INF);
  seen[s] = 0;
  deque<int> q;
  q.PB(s);
  
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
  
  return seen[t];
}

int dfs(vector<vector<int> > &grafo, vector<vector<int> > &flows, int ori, int &t, int act, int &path){
  int y, flujo = INF, acum = act + 1;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(acum == path and y != t) continue;
    else if(acum == path){
      flujo = 1;
      ft += flujo;
      flows[ori][y] -= flujo;
      flows[y][ori] += flujo;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == flujo) grafo[y].PB(ori);
      return flujo;
    }else{
      flujo = dfs(grafo, flows, y, t, acum, path);
      
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
  int n, c, tot, l, s, t, x, y, k;
  
  while(cin >> c >> n, c + n){
    s = n + c;
    t = s + 1;
    l = t + 1;
    tot = 0;
    
    vector<vector<int> > grafo(l), flows(l, vector<int> (l));
    
    FOR(i, 0, c){
      cin >> k;
      tot += k;
      grafo[n + i].PB(t);
      flows[n + i][t] = k;
    }
    
    FOR(i, 0, n){
      cin >> k;
      grafo[s].PB(i);
      flows[s][i] = 1;
      
      FOR(j, 0, k){
        cin >> x;
        x += (n - 1);
        grafo[i].PB(x);
        flows[i][x] = 1;
      }
    }
    
    ft = 0;
    
    while(true){
      x = bfs(grafo, s, t);
      if(x == INF) break;
      while(dfs(grafo, flows, s, t, 0, x) != INF){}
    }
    
    if(ft != tot) cout << "0\n";
    else{
      cout << "1\n";
      
      FOR(i, n, n + c){
        cout << grafo[i][0] + 1;
        
        FOR(j, 1, grafo[i].size()) cout << " " << grafo[i][j] + 1;
        cout << "\n";
      }
    }
  }
  
  return 0;
}