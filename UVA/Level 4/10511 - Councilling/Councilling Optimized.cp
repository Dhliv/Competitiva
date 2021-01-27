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

int bfs(int &ori, int &t, vector<vector<int> > &grafo){
  int y, n = grafo.size(), x;
  FOR(i, 0, n) se[i] = INF;
  se[ori] = 0;
  deque<int> p;
  p.PB(ori);
  
  while(!p.empty()){
    x = p.F();
    p.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      if(se[y] == INF){
        se[y] = se[x] + 1;
        p.PB(y);
      }
    }
  }
  
  return se[t];
}

int dfs(int ori, int &t, vector<vector<int> > &grafo, vector<vector<int> > &flows){
  int flujo = INF, y;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(y == t){
      flujo = 1;
      flows[ori][y] -= flujo;
      flows[y][ori] += flujo;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == flujo) grafo[y].PB(ori);
      return flujo;
    }else if(se[ori] + 1 == se[y]){
      flujo = dfs(y, t, grafo, flows);
      
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

string getN(int &pos, string ent){
  string na;
  FOR(i, pos, ent.size()){
    if(isspace(ent[i])){
      na = ent.substr(pos, i - pos);
      pos = i + 1;
      return na;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int cases, x, y, maxF, pos = 0, s, t, n, n1, n2;
  bool able;
  cin >> cases;
  string ent, na;
  getline(cin, ent);
  getline(cin, ent);
  
  FOR(ab, 0, cases){
    if(ab) cout << "\n";
    map<string, int> idn, idc, idp;
    deque<string> names, partys, clubs;
    deque<pair<int, int> > ptop, ctop;
    
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      ent += " ";
      pos = 0;
      na = getN(pos, ent);
      x = idn.size();
      idn.insert(MP(na, x));
      names.PB(na);
      
      na = getN(pos, ent);
      if(idp.find(na) == idp.end()){
        y = idp.size();
        idp.insert(MP(na, idp.size()));
        partys.PB(na);
      }else y = idp.find(na)->s;
      ptop.PB(MP(x, y));
      
      while(pos != ent.size()){
        na = getN(pos, ent);
        if(idc.find(na) == idc.end()){
          y = idc.size();
          idc.insert(MP(na, y));
          clubs.PB(na);
        }else y = idc.find(na)->s;
        
        ctop.PB(MP(y, x));
      }
    }
    
    n1 = clubs.size();
    n2 = n1 + names.size();
    n = n2 + partys.size();
    
    vector<vector<int> > grafo(n + 2), flows(n + 2, vector<int> (n + 2));
    se.resize(n + 2);
    s = n;
    t = s + 1;
    maxF = n1/2 - ((n1%2) ? 0 : 1);
    
    FOR(i, 0, n1){
      grafo[s].PB(i);
      flows[s][i] = 1;
    }
    
    FOR(i, 0, partys.size()){
      x = i + n2;
      if(maxF) grafo[x].PB(t);
      flows[x][t] = maxF;
    }
    
    FOR(i, 0, ctop.size()){
      x = ctop[i].f;
      y = ctop[i].s + n1;
      grafo[x].PB(y);
      flows[x][y] = 1;
    }
    
    FOR(i, 0, ptop.size()){
      x = ptop[i].f + n1;
      y = ptop[i].s + n2;
      grafo[x].PB(y);
      flows[x][y] = 1;
    }
    
    while(bfs(s, t, grafo) != INF){
      while(dfs(s, t, grafo, flows) != INF){}
    }
    
    able = true;
    FOR(i, 0, n1){
      if(flows[s][i] != 0){
        able = false;
        break;
      }
    }
    
    if(able){
      FOR(i, n1, n2){
        x = i - n1;
        FOR(j, 0, grafo[i].size()){
          y = grafo[i][j];
          if(y < n1){
            cout << names[x] << " " << clubs[y] << "\n";
            break;
          }
        }
      }
    }else cout << "Impossible.\n";
  }
  
  return 0;
}