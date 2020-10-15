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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

vector<vector<int> > grafo;
vector<int> seen, hijos;
priority_queue<int> pq;

void dfs(int nodo){
  
  FOR(i, 0, grafo[nodo].size()){
    if(seen[grafo[nodo][i]] == INF){
      seen[grafo[nodo][i]] = 1 + seen[nodo];
      dfs(grafo[nodo][i]);
      hijos[nodo] += 1 + hijos[grafo[nodo][i]];
      pq.push(seen[grafo[nodo][i]] - hijos[grafo[nodo][i]]);
    }
  }
}

int main() {
  int n, k, a, b, nodo, cont;
  ll ans = 0;
  cin >> n >> k;
  
  grafo.resize(n+1);
  seen.resize(n+1, INF);
  hijos.resize(n+1);
  
  FOR(i, 0, n-1){
    cin >> a >> b;
    grafo[a].PB(b);
    grafo[b].PB(a);
  }
  
  seen[1] = 0;
  dfs(1);
  
  while(k--){
    ans += pq.top();
    pq.pop();
  }
  
  cout << ans << "\n";
  
  return 0;
}