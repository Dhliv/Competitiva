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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int n, aris, qs, cases, nodo, nodoD, x, y, val;
  ll cost;
  string ent, ori, dest;
  cin >> cases;
  cout << "SHIPPING ROUTES OUTPUT\n\n";
  
  FOR(a, 0, cases){
    cout << "DATA SET  " << a+1 << "\n\n";
    
    cin >> n >> aris >> qs;
    vector<vector<int> > grafo(n);
    map<string, int> ids;
    
    FOR(i, 0, n){
      cin >> ent;
      ids.insert(MP(ent, i));
    }
    
    FOR(i, 0, aris){
      cin >> ori >> dest;
      x = ids.find(ori)->s;
      y = ids.find(dest)->s;
      grafo[x].PB(y);
      grafo[y].PB(x);
    }
    
    FOR(i, 0, qs){
      cin >> val >> ori >> dest;
      nodo = ids.find(ori)->s;
      nodoD = ids.find(dest)->s;
      cost = val*100;
      
      deque<int> q;
      q.PB(nodo);
      vector<int> seen(n, INF);
      seen[nodo] = 0;
      
      while(!q.empty()){
        nodo = q.F();
        q.P_F();
        
        FOR(j, 0, grafo[nodo].size()){
          x = grafo[nodo][j];
          if(seen[x] == INF){
            seen[x] = seen[nodo] + 1;
            q.PB(x);
          }
        }
      }
      
      if(seen[nodoD] == INF) cout << "NO SHIPMENT POSSIBLE\n";
      else{
        cost *= seen[nodoD];
        cout << "$" << cost << "\n";
      }
    }
    cout << "\n";
  }
  
  cout << "END OF OUTPUT\n";
  
  return 0;
}
