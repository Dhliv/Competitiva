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

int main() {
  int cases, celdas, salida, taim, aris, a, b, p, nodo, nodoD, ans;
  cin >> cases;
  
  FOR(c, 0, cases){
    if(c) cout << "\n";
    cin >> celdas >> salida >> taim >> aris;
    vector<vector<int> > grafo(celdas + 1), vals(celdas + 1, vector<int> (celdas + 1));
    ans = 0;
    
    FOR(i, 0, aris){
      cin >> a >> b >> p;
      grafo[b].PB(a);
      vals[b][a] = p;
    }
    
    priority_queue<pair<int, int> > pq;
    pq.push(MP(0, salida));
    vector<int> visit(celdas + 1), taims(celdas + 1, INF);
    taims[salida] = 0;
    
    while(!pq.empty()){
      nodo = pq.top().s;
      pq.pop();
      
      if(visit[nodo]) continue;
      visit[nodo] = 1;
      
      FOR(i, 0, grafo[nodo].size()){
        nodoD = grafo[nodo][i];
        if(visit[nodoD]) continue;
        if(taims[nodoD] > taims[nodo] + vals[nodo][nodoD]){
          taims[nodoD] = taims[nodo] + vals[nodo][nodoD];
          pq.push(MP(-taims[nodoD], nodoD));
        }
      }
    }
    
    FOR(i, 1, celdas + 1){
      if(taim >= taims[i]) ans++;
    }
      
    cout << ans << "\n";
  }

	return 0;
}