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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, edges, querys;
  string aux, ent, nodo, nodoD, nodoAux;
  cin >> cases;
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    cin >> edges >> querys;
    map<string, vector<string> > grafo;
    
    FOR(i, 0, edges){
      cin >> nodo >> nodoD;
      
      if(grafo.find(nodo) == grafo.end()){
        vector<string> m{nodoD};
        grafo.insert(MP(nodo, m));
      }else
        grafo[nodo].PB(nodoD);
        
      if(grafo.find(nodoD) == grafo.end()){
        vector<string> m{nodo};
        grafo.insert(MP(nodoD, m));
      }else
        grafo[nodoD].PB(nodo);
    }
    
    FOR(i, 0, querys){
      cin >> nodo >> nodoD;
      map<string, string> seen;
      seen.insert(MP(nodo, nodo.substr(0, 1)));
      deque<string> dq;
      dq.PB(nodo);
      
      while(!dq.empty()){
        nodo = dq.F();
        dq.P_F();
        
        FOR(b, 0, grafo[nodo].size()){
          if(seen.find(grafo[nodo][b]) == seen.end()){
            seen.insert(MP(grafo[nodo][b], seen[nodo] + grafo[nodo][b].substr(0, 1)));
            dq.PB(grafo[nodo][b]);
          }
        }
      }
      
      cout << seen[nodoD] + "\n";
    }
  }
  
  return 0;
}