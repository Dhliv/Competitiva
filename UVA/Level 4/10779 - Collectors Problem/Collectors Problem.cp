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

bool able;
int entrada;

int tbfs(vector<vector<int> > &grafo, int &s, int &t){
  int x, y, k = 1;
  vector<int> seen(grafo.size(), INF);
  deque<int> q;
  seen[s] = 0;
  q.PB(s);
  
  while(!q.empty()){
    set<int> next;
    while(!q.empty()){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        if(seen[y] == INF) next.insert(y);
      }
    }
    
    forit(a, next){
      if(k == 2 and *a == t) q.PB(t);
      else{
        seen[*a] = k;
        q.PB(*a);
      }
    }
    k++;
  }
  
  return seen[t];
}

int dfs(vector<vector<int> > &grafo, vector<vector<int> > &flows, int ori, int &t, int act, int &path, int padre){
  int y, acum = act + 1, flujo = INF;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(acum == path and y != t) continue;
    else if(acum == path and padre == 0) continue;
    else if(acum == path and entrada == ori) continue;
    else if(acum == path){
      able = true;
      flujo = 1;
      flows[ori][y] -= flujo;
      flows[y][ori] += flujo;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == flujo) grafo[y].PB(ori);
      return flujo;
    }else if(y != ori){
      if(acum == 1) entrada = y;
      flujo = dfs(grafo, flows, y, t, acum, path, ori);
      
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
  int n, m, k, cases, s, t, ans, l, x, y;
  cin >> cases;
  
  FOR(a, 0, cases){
    cout << "Case #" << a + 1 << ": ";
    cin >> n >> m;
    l = n + m + 1;
    s = 0;
    t = l - 1;
    vector<vector<int> > grafo(l), flows(l, vector<int> (l));
    
    cin >> k;
    FOR(i, 0, k){
      cin >> y;
      flows[s][y] += 1;
    }
    
    FOR(i, 1, m + 1) if(flows[s][i]) grafo[s].PB(i);
    
    FOR(i, 1, n){
      cin >> k;
      x = i + m;
      
      FOR(j, 0, k){
        cin >> y;
        flows[x][y] += 1;
      }
    }
    
    FOR(i, 1, n){
      x = i + m;
      
      FOR(j, 1, m + 1){
        if(flows[x][j] > 0){
          flows[x][j] -= 1;
          if(flows[x][j] > 0) grafo[x].PB(j);
        }else if(flows[x][j] == 0){
          grafo[j].PB(x);
          flows[j][x] = 1;
        }
      }
    }
    
    FOR(i, 1, m + 1){
      flows[i][t] = 1;
      grafo[i].PB(t);
    }

    while(true){
      x = tbfs(grafo, s, t);
      if(x == INF) break;
      able = false;
      entrada = -1;
      vector<int> seen(l, 0);
      while(dfs(grafo, flows, s, t, 0, x, -1) != INF){ entrada = -1;}
      if(!able) break;
    }
    
    ans = 0;
    FOR(i, 1, m + 1) if(flows[t][i] or flows[s][i]) ans++;
    
    cout << ans << "\n";
  }
  
  return 0;
}