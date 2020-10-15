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
  int n, m, a, b, c, nodo;
  cin >> n >> m;
  vector<vector<pair<int, int> > > grafo(n + 1);
  
  FOR(i, 0, m){
    cin >> a >> b >> c;
    grafo[a].PB(MP(b, c));
    grafo[b].PB(MP(a, c));
  }
  
  priority_queue<pair<ll, int> > pq;
  pq.push(MP(0, 1));
  vector<int> seen(n+1, INF), pads(n+1), visit(n+1);
  pads[1] = 0;
  seen[1] = 0;
  
  while(!pq.empty()){
    nodo = pq.top().s;
    pq.pop();
    
    if(visit[nodo]) continue;
    visit[nodo] = 1;
    
    FOR(i, 0, grafo[nodo].size()){
      if(visit[grafo[nodo][i].f]) continue;
      
      if(seen[grafo[nodo][i].f] > seen[nodo] + grafo[nodo][i].s){
        seen[grafo[nodo][i].f] = seen[nodo] + grafo[nodo][i].s;
        pads[grafo[nodo][i].f] = nodo;
        pq.push(MP(-seen[grafo[nodo][i].f], grafo[nodo][i].f));
      }
    }
  }
  
  if(pads[n] == 0) cout << -1 << "\n";
  else{
    deque<int> pila;
    pila.PB(n);
    while(pads[n]){
      n = pads[n];
      pila.PB(n);
    }
    while(!pila.empty()){
      cout << pila.B() << " ";
      pila.P_B();
    }
    cout << "\n";
  }

	return 0;
}