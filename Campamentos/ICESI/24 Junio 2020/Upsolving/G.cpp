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

int n, edges, a, b, best = MINF;
vector<vector<int> > grafo;
vector<int> seen;

void dfs(int nodo){
  int maxi = 0;
  
  FOR(i, 0, grafo[nodo].size()){
    if(seen[grafo[nodo][i]] == MINF)
      dfs(grafo[nodo][i]);
        
    if(seen[grafo[nodo][i]] + 1 > maxi)
      maxi = 1 + seen[grafo[nodo][i]];
  }
  seen[nodo] = maxi;
}

int main() {
  cin >> n >> edges;
  grafo.resize(n+1);
  seen.resize(n+1, MINF);
  vector<int> origenes(n+1, 1);
  
  FOR(i, 0, edges){
    cin >> a >> b;
    grafo[a].PB(b);
    origenes[b] = 0;
  }
  
  FOR(i, 1, n+1){
    if(origenes[i]){
      dfs(i);
      if(seen[i] > best)
        best = seen[i];
    }
  }
  
  cout << best << "\n";

  return 0;
}