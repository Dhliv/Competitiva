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

int main() {
  int x, y, cases, cas;
  pair<int, int> nodo;
  cin >> cases;
  
  FOR(a, 0, cases){
    cout << "Case " << a+1 << ": ";
    
    cin >> x >> y;
    vector<vector<vector<pair<int, int> > > > grafo(y);
    vector<string> data(y);
    
    FOR(i, 0, y){
      vector<vector<pair<int, int> > > aux(x);
      grafo[i] = aux;
    }
    
    FOR(i, 0, y){
      cin >> data[i];
      FOR(j, 0, x){
        if(data[i][j] == '@')
          nodo = MP(i, j);
      }
    }
    
    //Armar grafo
    
    FOR(i, 0, y){
      FOR(j, 0, x){
        if(data[i][j] != '#'){
          if(i+1 < y and data[i+1][j] != '#'){
            grafo[i][j].PB(MP(i+1, j));
            grafo[i+1][j].PB(MP(i, j));
          }
          if(j+1 < x and data[i][j+1] != '#'){
            grafo[i][j].PB(MP(i, j+1));
            grafo[i][j+1].PB(MP(i, j));
          }
        }
      }
    }
    
    cas = 1;
    deque<pair<int, int> > dq;
    dq.PB(nodo);
    vector<vector<int> > seen(y);
    
    FOR(i, 0, y){
      vector<int> aux(x, INF);
      seen[i] = aux;
    }
    
    seen[nodo.first][nodo.second] = 0;
    
    while(!dq.empty()){
      nodo = dq.F();
      dq.P_F();
      
      FOR(i, 0, grafo[nodo.first][nodo.second].size()){
        if(seen[grafo[nodo.first][nodo.second][i].first][grafo[nodo.first][nodo.second][i].second] == INF){
          cas++;
          seen[grafo[nodo.first][nodo.second][i].first][grafo[nodo.first][nodo.second][i].second] = 0;
          dq.PB(grafo[nodo.first][nodo.second][i]);
        }
      }
    }
    
    cout << cas << "\n";
  }

  return 0;
}