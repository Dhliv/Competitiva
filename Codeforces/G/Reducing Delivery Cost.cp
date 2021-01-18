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
  int n, m, k, x, y, ans = 0, w, ori, dest, mini, a, b;
  cin >> n >> m >> k;

  vector<vector<int> > grafo(n + 1), cost(n + 1, vector<int> (n + 1)), d(n + 1, vector<int> (n + 1));
  vector<pair<int, int> > ars(m), caminos(k);
  
  FOR(i, 0, m){
    cin >> x >> y >> w;
    grafo[x].PB(y);
    grafo[y].PB(x);
    cost[x][y] = cost[y][x] = w;
    ars[i] = MP(x, y);
  }
  
  priority_queue<pair<int, int> > q;
  
  FOR(a, 1, n + 1){
    vector<int> seen(n + 1, INF);
    vector<bool> vistos(n + 1);
    seen[a] = 0;
    q.push(MP(0, a));
    
    while(!q.empty()){
      x = q.top().s;
      q.pop();
      
      if(vistos[x]) continue;
      vistos[x] = true;
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        w = cost[x][y] + seen[x];
        
        if(seen[y] > w){
          seen[y] = w;
          q.push(MP(-w, y));
        }
      }
    }
    
    FOR(i, 1, n + 1){
      d[a][i] = seen[i];
    }
  }
  
  FOR(i, 0, k){
    cin >> a >> b;
    caminos[i] = MP(a, b);
  }
  
 ans = INF;
  FOR(i, 0, m){
    x = ars[i].f; y = ars[i].s;
    mini = 0;
    FOR(j, 0, k){
      a = caminos[j].f; b = caminos[j].s;
      mini += min(d[a][b], min(d[a][x] + d[y][b], d[a][y] + d[x][b]));
    }
    ans = min(ans, mini);
  }
  
  cout << ans << "\n";
  
  return 0;
}