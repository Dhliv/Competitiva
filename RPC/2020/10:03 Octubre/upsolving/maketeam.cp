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

int bfs(vector<vector<int> > &grafo, int ori, int dest){
  int x, y;
  vector<int> seen(grafo.size(), INF);
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

int dfs(vector<vector<int> > &grafo, vector<vector<int> > &flows, int ori, int &dest, int act, int &path, int mini){
  int x, y, flujo = INF, acum = act + 1;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(acum == path and y != dest) continue;
    else if(acum == path){
      ft++;
      flujo = min(mini, flows[ori][y]);
      flows[ori][y] = 0;
      flows[y][ori] = 1;
      grafo[ori].erase(grafo[ori].begin() + i);
      grafo[y].PB(ori);
      return flujo;
    }else{
      flujo = dfs(grafo, flows, y, dest, acum, path, min(mini, flows[ori][y]));
      if(flujo != INF){
        flows[ori][y] = 0;
        flows[y][ori] = 1;
        grafo[ori].erase(grafo[ori].begin() + i);
        grafo[y].PB(ori);
        return flujo;
      }
    }
  }
  
  return flujo;
}

int main(){
  int n, k, t, l = 1002, s, x, y, mini = MINF;
  cin >> n;
  vector<vector<int> > grafo(l + n + 1), flows(l + n + 1, vector<int> (l + n + 1)), g1, f1;
  t = l + n;
  s = t - 1;
  set<int> times;
  
  FOR(i, -1, n - 1){
    cin >> k;
    grafo[l + i].PB(t);
    flows[l + i][t] = 1;
    FOR(j, 0, k){
      cin >> x;
      grafo[x].PB(l + i);
      flows[x][l + i] = 1;
      if(times.find(x) == times.end()) times.insert(x);
    }
  }
  
  vector<int> tiempos(times.size());
  x = 0;
  forit(a, times){
    flows[s][*a] = 1;
    grafo[s].PB(*a);
    tiempos[x++] = *a;
  }
  
  int low = n - 1, high = times.size() - 1, mid;
  
  while(low <= high){
    mid = (low + high)/2;
    g1 = grafo;
    f1 = flows;
    
    g1[s].erase(g1[s].begin() + mid + 1, g1[s].end());
    
    ft = 0;
    while(true){
      x = bfs(g1, s, t);
      if(x == INF) break;
      else{
        while(dfs(g1, f1, s, t, 0, x, INF) != INF){}
      }
    }
    
    if(ft == n) high = mid - 1;
    else low = mid + 1;
  }
  
  cout << tiempos[low] + 1 << "\n";
  
  return 0;
}