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
  int filas, columnas, withB, fi, bombs, aux, x, y;
  pair<int, int> nodo, nodoD;
  
  while(cin >> filas >> columnas, filas+columnas){
    cin >> withB;
    vector<vector<int> > grafo(filas), seen(filas);
    vector<int> cols(columnas, INF);
    
    FOR(i, 0, filas){
      grafo[i] = cols;
      seen[i] = cols;
    }
    
    FOR(i, 0, withB){
      cin >> fi >> bombs;
      FOR(j, 0, bombs){
        cin >> aux;
        grafo[fi][aux] = 0;
      }
    }
    
    cin >> fi >> aux;
    nodo = MP(fi, aux);
    cin >> fi >> aux;
    nodoD = MP(fi, aux);
    
    deque<pair<int, int> > dq;
    dq.PB(nodo);
    seen[nodo.first][nodo.second] = 0;
    
    while(!dq.empty()){
      nodo = dq.F();
      x = nodo.first;
      y = nodo.second;
      dq.P_F();
      
      if(x-1 >= 0 and grafo[x-1][y] and seen[x-1][y] == INF){
        seen[x-1][y] = seen[x][y] + 1;
        dq.PB(MP(x-1, y));
      }
      if(x+1 < filas and grafo[x+1][y] and seen[x+1][y] == INF){
        seen[x+1][y] = seen[x][y] + 1;
        dq.PB(MP(x+1, y));
      }
      if(y-1 >= 0 and grafo[x][y-1] and seen[x][y-1] == INF){
        seen[x][y-1] = seen[x][y] + 1;
        dq.PB(MP(x, y-1));
      }
      if(y+1 < columnas and grafo[x][y+1] and seen[x][y+1] == INF){
        seen[x][y+1] = seen[x][y] + 1;
        dq.PB(MP(x, y+1));
      }
    }
    
    cout << seen[nodoD.first][nodoD.second] << "\n";
  }
  
  return 0;
}