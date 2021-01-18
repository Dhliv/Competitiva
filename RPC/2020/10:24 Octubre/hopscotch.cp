#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
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
  int n, k, x, y, ans, w;
  cin >> n >> k;
  vector<vector<pair<int, int> > > grafo(k + 1);
  
  FOR(i, 0, n){
    FOR(j, 0, n){
      cin >> x;
      grafo[x].PB(MP(i, j));
    }
  }
  
  vector<vector<int> > seen(n, vector<int> (n, INF)), vistos(n, vector<int> (n));
  priority_queue<pair<int, pair<int, pair<int, int> > > > p; // peso, losa, coord.
  pair<int, int> par, sec;
  
  FOR(i, 0, grafo[1].size()){
    par = grafo[1][i];
    seen[par.f][par.s] = 0;
    p.push(MP(0, MP(1, par)));
  }
  
  while(!p.empty()){
    par = p.top().s.s;
    x = p.top().s.f;
    p.pop();
    
    if(vistos[par.f][par.s] or x == k) continue;
    vistos[par.f][par.s] = 1;
    
    FOR(i, 0, grafo[x + 1].size()){
      sec = grafo[x + 1][i];
      w = seen[par.f][par.s] + abs(par.f - sec.f) + abs(par.s - sec.s);
      if(seen[sec.f][sec.s] > w){
        seen[sec.f][sec.s] = w;
        p.push(MP(-w, MP(x + 1, sec)));
      }
    }
  }
  
  ans = INF;
  
  FOR(i, 0, grafo[k].size()){
    par = grafo[k][i];
    ans = min(ans, seen[par.f][par.s]);
  }
  
  if(ans == INF) cout << "-1\n";
  else cout << ans << "\n";
  
  return 0;
}