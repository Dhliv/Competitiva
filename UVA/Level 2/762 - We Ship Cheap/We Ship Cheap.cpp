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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int n, nodo, x, y, nodoD, cont = 0;
  string ori, dest, a, b;
  
  while(cin >> n){
    if(cont++) cout << "\n";
    
    vector<string> names;
    map<string, int> ids;
    vector<pair<int, int> > tA;
    
    FOR(i, 0, n){
      cin >> a >> b;
      
      if(ids.find(a) == ids.end()){
        ids.insert(MP(a, names.size()));
        names.PB(a);
      }
      
      if(ids.find(b) == ids.end()){
        ids.insert(MP(b, names.size()));
        names.PB(b);
      }
      
      x = ids.find(a)->s;
      y = ids.find(b)->s;
      
      tA.PB(MP(x, y));
    }
    
    vector<vector<int> > grafo(names.size());
    
    FOR(i, 0, tA.size()){
      grafo[tA[i].f].PB(tA[i].s);
      grafo[tA[i].s].PB(tA[i].f);
    }
    
    cin >> ori >> dest;
    
    if(ids.find(ori) == ids.end() or ids.find(dest) == ids.end()) cout << "No route\n";
    else{
      nodo = ids.find(ori)->s;
      nodoD = ids.find(dest)->s;
      deque<int> q;
      q.PB(nodo);
      vector<int> seen(names.size(), INF);
      vector<pair<string, int> > way(names.size(), MP("", -1));
      seen[nodo] = 0;
      
      while(!q.empty() and seen[nodoD] == INF){
        nodo = q.F();
        q.P_F();
        
        FOR(i, 0, grafo[nodo].size()){
          x = grafo[nodo][i];
          if(seen[x] == INF){
            seen[x] = 1 + seen[nodo];
            way[x] = MP(names[nodo] + " " + names[x], nodo);
            q.PB(x);
          }
        }
      }
      
      if(seen[nodoD] == INF) cout << "No route\n";
      else{
        deque<string> pila;
        while(way[nodoD].f != ""){
          pila.PB(way[nodoD].f);
          nodoD = way[nodoD].s;
        }
        
        while(!pila.empty()){
          cout << pila.B() << "\n";
          pila.P_B();
        }
      }
    }
  }
  
  return 0;
}
