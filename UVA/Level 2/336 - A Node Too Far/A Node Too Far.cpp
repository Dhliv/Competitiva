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
  int edges, n1, n2, cont, nodo, TTL, pos, nodoO, casos = 1, nodos, vNodoO;
  
  while(cin >> edges, edges){
    map<int, int> pres;
    vector<vector<int> > grafo(31);
    cont = 0;
    
    FOR(i, 0, edges){
      cin >> n1 >> n2;
      if(pres.find(n1) == pres.end()){
        grafo[cont].PB(n2);
        pres.insert(MP(n1, cont));
        cont++;
      }else
        grafo[pres.find(n1)->second].PB(n2);
        
      if(pres.find(n2) == pres.end()){
        grafo[cont].PB(n1);
        pres.insert(MP(n2, cont));
        cont++;
      }else
        grafo[pres.find(n2)->second].PB(n1);
    }
    nodos = cont;
    
    //Querys:
    
    while(cin >> nodo >> TTL, nodo+TTL){
      vector<int> seen(31, INF);
      deque<int> dq, will;
      nodoO = pres.find(nodo)->second, cont = 1, vNodoO = nodo;
      dq.PB(nodo);
      seen[nodoO] = TTL;
      
      while(seen[nodoO]){
        
        while(!dq.empty()){
          nodo = dq.F();
          dq.P_F();
          pos = pres.find(nodo)->second;
          
          FOR(i, 0, grafo[pos].size()){
            if(seen[pres.find(grafo[pos][i])->second] == INF){
              seen[pres.find(grafo[pos][i])->second] = 0;
              will.PB(grafo[pos][i]);
              cont++;
            }
          }
        }
        if(will.empty()) break;
        
        dq.swap(will);
        
        seen[nodoO] -= 1;
      }
      
      cout << "Case " << casos++ << ": " << nodos - cont << " nodes not reachable from node ";
      cout << vNodoO << " with TTL = " << TTL << ".\n";
    }
  }
  
  return 0;
}