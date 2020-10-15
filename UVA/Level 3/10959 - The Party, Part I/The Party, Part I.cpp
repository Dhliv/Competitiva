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
  int cases, p, aris, x, y;
  cin >> cases;
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    
    cin >> p >> aris;
    vector<vector<int> > grafo(p);
    
    FOR(i, 0, aris){
      cin >> x >> y;
      grafo[x].PB(y);
      grafo[y].PB(x);
    }
    
    deque<int> q;
    q.PB(0);
    vector<int> seen(p, INF);
    seen[0] = 0;
    
    while(!q.empty()){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        if(seen[y] == INF){
          seen[y] = 1 + seen[x];
          q.PB(y);
        }
      }
    }
    
    FOR(i, 1, p) cout << seen[i] << "\n";
  }
  
  return 0;
}
