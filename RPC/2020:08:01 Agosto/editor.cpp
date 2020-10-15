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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, lines, posri, posrf, posci, poscf;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> lines;
    vector<int> lgs(lines);
    
    FOR(i, 0, lines) cin >> lgs[i];
    
    vector<vector<vector<pair<int, int> > > > grafo(lines + 1, vector<vector<pair<int, int> > >(81));
    
    FOR(i, 0, lines){
      FOR(j, 0, lgs[i] + 1){
        if(j + 1 <= lgs[i]){
          grafo[i][j].PB(MP(i, j + 1));
          grafo[i][j + 1].PB(MP(i, j));
        }
        else if(i + 1 < lines){
          grafo[i][j].PB(MP(i + 1, 0));
          grafo[i + 1][0].PB(MP(i, j));
        }
        if(i + 1 < lines){
          if(j <= lgs[i + 1]){
            grafo[i][j].PB(MP(i + 1, j));
          }else{
            grafo[i][j].PB(MP(i + 1, lgs[i + 1]));
          }
        }
        if(i - 1 >= 0){
          if(j <= lgs[i - 1]){
            grafo[i][j].PB(MP(i - 1, j));
          }else{
            grafo[i][j].PB(MP(i - 1, lgs[i - 1]));
          }
        }
      }
    }
    
    cin >> posri >> posci;
    cin >> posrf >> poscf;
    posri--, posrf--;
    
    pair<int, int> nodo, x;
    deque<pair<int, int> > dq;
    dq.PB(MP(posri, posci));
    vector<vector<int> > seen(lines, vector<int>(81, INF));
    seen[posri][posci] = 0;
    
    while(!dq.empty() and seen[posrf][poscf] == INF){
      nodo = dq.F();
      dq.P_F();
      
      FOR(i, 0, grafo[nodo.f][nodo.s].size()){
        x = grafo[nodo.f][nodo.s][i];
        if(seen[x.f][x.s] == INF){
          seen[x.f][x.s] = seen[nodo.f][nodo.s] + 1;
          dq.PB(x);
        }
      }
    }
    
    cout << seen[posrf][poscf] << "\n";
  }
  
  return 0;
}