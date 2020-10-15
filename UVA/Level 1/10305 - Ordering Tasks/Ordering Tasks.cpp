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

deque<int> topo;

void topol(vector<vector<int> > &grafo, vector<int> &seen, int nodo){
  FOR(i, 0, grafo[nodo].size()){
    if(seen[grafo[nodo][i]]){
      seen[grafo[nodo][i]] = 0;
      topol(grafo, seen, grafo[nodo][i]);
      topo.PF(grafo[nodo][i]);
    }
  }
}

int main(){
  int n, m, x, y;
  
  while(cin >> n >> m, n + m){
    vector<vector<int> > grafo(n+1);
    vector<int> seen(n+1, 1);
    
    FOR(i, 0, m){
      cin >> x >> y;
      grafo[x].PB(y);
    }
    
    FOR(i, 1, n+1){
      if(seen[i]){
        seen[i] = 0;
        topol(grafo, seen, i);
        topo.PF(i);
      }
    }
    
    while(topo.size() > 1){
      cout << topo.F() << " ";
      topo.P_F();
    }
    cout << topo.F() << "\n";
    topo.P_F();
  }
  
  return 0;
}