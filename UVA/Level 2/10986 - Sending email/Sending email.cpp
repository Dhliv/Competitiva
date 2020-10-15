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
  int cases, servers, aris, ori, dest, a, b, p, nodo, nodoD;
  ll ans;
  
  cin >> cases;
  
  FOR(c, 0, cases){
    cout << "Case #" << c+1 << ": ";
    cin >> servers >> aris >> ori >> dest;
    vector<vector<int> > grafo(servers), vals(servers, vector<int> (servers));
    
    FOR(i, 0, aris){
      cin >> a >> b >> p;
      grafo[a].PB(b);
      grafo[b].PB(a);
      vals[a][b] = p;
      vals[b][a] = p;
    }
    
    priority_queue<pair<int, int> > pq;
    pq.push(MP(0, ori));
    vector<int> visit(servers, 0), dist(servers, INF);
    dist[ori] = 0;
    
    while(!pq.empty()){
      nodo = pq.top().s;
      pq.pop();
      
      if(visit[nodo]) continue;
      visit[nodo] = 0;
      
      FOR(i, 0, grafo[nodo].size()){
        nodoD = grafo[nodo][i];
        if(visit[nodoD]) continue;
        if(dist[nodoD] > dist[nodo] + vals[nodo][nodoD]){
          dist[nodoD] = dist[nodo] + vals[nodo][nodoD];
          pq.push(MP(-dist[nodoD], nodoD));
        }
      }
    }
    
    if(dist[dest] == INF)
      cout << "unreachable\n";
    else
      cout << dist[dest] << "\n";
  }

	return 0;
}