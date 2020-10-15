#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int t, n, c, val, u, aris, x, y, nodo, nodoD;
  string ori, dest, mo;
  map<string, int> mod;
  mod.insert(MP("AIR", 0));
  mod.insert(MP("SEA", 1));
  mod.insert(MP("RAIL", 2));
  mod.insert(MP("TRUCK", 3));
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    vector<vector<vector<int> > > grafo(n, vector<vector<int> > (n)), ady(n, vector<vector<int> > (n, vector<int> (4)));
    vector<vector<int> > conex(n);
    map<string, int> rep;
    vector<int> valores(n);
    
    FOR(i, 0, n){
      cin >> ori >> val;
      rep.insert(MP(ori, i));
      valores[i] = val;
    }
    
    cin >> aris;
    
    FOR(i, 0, aris){
      cin >> ori >> dest >> mo >> c;
      x = rep.find(ori)->s;
      y = rep.find(dest)->s;
      u = mod.find(mo)->s;
      
      if(grafo[x][y].size() == 0){
        conex[x].PB(y);
        conex[y].PB(x);
      }
      
      grafo[x][y].PB(u);
      grafo[y][x].PB(u);
      ady[x][y][u] = c;
      ady[y][x][u] = c;
    }
    
    cin >> ori >> dest;
    nodo = rep.find(ori)->s;
    nodoD = rep.find(dest)->s;
    priority_queue<pair<int, int> > dq;
    vector<int> vistos(n);
    vector<vector<int> > seen(n, vector<int> (4, INF));
    
    FOR(i, 0, 4) seen[nodo][i] = 0;
    dq.push(MP(0, nodo));
    
    while(!dq.empty()){
      nodo = dq.top().s;
      dq.pop();
      
      if(vistos[nodo]) continue;
      vistos[nodo] = 1;
      
      FOR(i, 0, conex[nodo].size()){
        val = conex[nodo][i];
        if(vistos[val]) continue;
        x = INF;
        
        FOR(k, 0, 4){
          if(seen[nodo][k] == INF) continue;
        
          FOR(j, 0, grafo[nodo][val].size()){
            c = 0;
            if(k != grafo[nodo][val][j]) c = valores[nodo];
            
            if(seen[val][grafo[nodo][val][j]] > c + seen[nodo][k] + ady[nodo][val][grafo[nodo][val][j]]){
              seen[val][grafo[nodo][val][j]] = c + seen[nodo][k] + ady[nodo][val][grafo[nodo][val][j]];
              if(x > seen[val][grafo[nodo][val][j]]) x = seen[val][grafo[nodo][val][j]];
            }
          }
        }
        
        if(x) dq.push(MP(-x, val));
      }
    }
    
    //BUSCAR MINIMA LLEGADA:
    x = INF;
    FOR(i, 0, 4) if(x > seen[nodoD][i]) x = seen[nodoD][i];
    
    cout << x << "\n";
    
  }
  
  return 0;
}