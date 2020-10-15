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
  deque<int> q;
  seen[s] = 0;
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
  int y, acum = act + 1, flujo = INF;
  
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
  int cases, x, y, f, s, t, pos;
  string ent, name, party;
  vector<int> vacio;
  
  cin >> cases;
  getline(cin, ent);
  getline(cin, ent);
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    deque<string> obj;
    deque<int> partidos, clubes, nombres;
    map<string, int> idn, idp, idc;
    map<int, string> nn, np, nc;
    map<int, vector<int> > conexn, conexp;
    vector<int> aux;
    
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      pos = 0;
      FOR(i, 0, ent.size()){
        if(isspace(ent[i])){
          obj.PB(ent.substr(pos, i - pos));
          pos = i + 1;
        }else if(i + 1 == ent.size()) obj.PB(ent.substr(pos, ent.size() - pos));
      }
      
      name = obj.F(); obj.P_F();
      party = obj.F(); obj.P_F();
      x = idn.size() + idp.size() + idc.size();
      idn.insert(MP(name, x));
      nn.insert(MP(x, name));
      nombres.PB(x);
      conexn.insert(MP(nombres.B(), vacio));
      
      if(idp.find(party) == idp.end()){
        x = idn.size() + idp.size() + idc.size();
        idp.insert(MP(party, x));
        np.insert(MP(x, party));
        partidos.PB(x);
        conexp.insert(MP(partidos.B(), vacio));
      }
      
      x = idn.find(name)->s;
      conexp[idp.find(party)->s].PB(x);
      
      while(!obj.empty()){
        if(idc.find(obj.F()) == idc.end()){
          y = idn.size() + idp.size() + idc.size();
          idc.insert(MP(obj.F(), y));
          nc.insert(MP(y, obj.F()));
          clubes.PB(y);
        }
        conexn[x].PB(idc.find(obj.F())->s);
        obj.P_F();
      }
    }
    
    s = idn.size() + idp.size() + idc.size();
    t = s + 1;
    f = (clubes.size() - 1)/2;
    
    vector<vector<int> > grafo(t + 1), flows(t + 1, vector<int> (t + 1));
    
    FOR(i, 0, partidos.size()){
      x = partidos[i];
      grafo[s].PB(x);
      flows[s][x] = f;
      aux = conexp[x];
      
      if(f != 0){
        FOR(j, 0, aux.size()){
          y = aux[j];
          grafo[x].PB(y);
          flows[x][y] = 1;
        }
      }
    }
    
    FOR(i, 0, nombres.size()){
      x = nombres[i];
      aux = conexn[x];
      
      FOR(j, 0, aux.size()){
        y = aux[j];
        grafo[x].PB(y);
        flows[x][y] = 1;
      }
    }
    
    FOR(i, 0, clubes.size()){
      x = clubes[i];
      grafo[x].PB(t);
      flows[x][t] = 1;
    }
    
    ft = 0;
    while(true){
      x = bfs(grafo, s, t);
      if(x == INF) break;
      while(dfs(grafo, flows, s, t, 0, x) != INF){}
    }
    
    if(ft == clubes.size()){
      vector<pair<int, string> > imp;
      
      FOR(i, 0, clubes.size()){
        x = clubes[i];
        imp.PB(MP(grafo[x][0], nc.find(x)->s));
      }
      
      sort(imp.begin(), imp.end());
      
      FOR(i, 0, imp.size()){
        cout << nn.find((imp[i].f))->s << " " + imp[i].s + "\n";
      }
    }else cout << "Impossible.\n";
  }
  
  return 0;
}