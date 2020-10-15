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
      ft++;
      flows[ori][t] -= 1;
      flows[t][ori] += 1;
      if(flows[ori][t] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[t][ori] == 1) grafo[t].PB(ori);
      return 1;
    }else{
      flujo = dfs(grafo, flows, y, t, acum, path);
      if(flujo != INF){
        flows[ori][y] -= 1;
        flows[y][ori] += 1;
        if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
        if(flows[y][ori] == 1) grafo[y].PB(ori);
        return 1;
      }
    }
  }
  
  return flujo;
}

int main(){
  int cases, n, m, x, y, l = 38, s = 36, t = 37, fl;
  string talla;
  vector<string> names{"XXL", "XL", "L", "M" , "S", "XS"};
  cin >> cases;
  
  map<string, int> ids;
  
  FOR(i, 0, names.size()) ids.insert(MP(names[i], 30 + i));
  
  FOR(abcd, 0, cases){
    cin >> n >> m;
    fl = n/6;
    
    vector<vector<int> > grafo(l), flows(l, vector<int> (l));
    FOR(i, 0, 6){
      grafo[30 + i].PB(t);
      flows[30 + i][t] = fl;
    }
    
    FOR(i, 0, m){
      grafo[s].PB(i);
      flows[s][i] = 1;
      
      FOR(j, 0, 2){
        cin >> talla;
        x = ids.find(talla)->s;
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
    
    if(ft == m) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}