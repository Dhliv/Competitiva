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

void bfs(vector<vector<int> > &grafo, vector<int> &d, int a){
  int nodo;
  deque<int> dq;
  dq.PF(a);
  
  while(!dq.empty()){
    nodo = dq.F();
    dq.P_F();
    
    FOR(i, 0, grafo[nodo].size()){
      if(d[grafo[nodo][i]] == INF){
        d[grafo[nodo][i]] = d[nodo] + 1;
        dq.PB(grafo[nodo][i]);
      }
    }
  }
}

int main(){
  int t, n, a, b, c, m, x, y, nodo;
  ll ans, xx;
  cin >> t;
  
  FOR(ant, 0, t){
    cin >> n >> m >> a >> b >> c;
    vector<vector<int> > grafo(n + 1);
    vector<int> d1(n + 1, INF), d2(n + 1, INF), d3(n + 1, INF);
    vector<ll> dat(m + 1), ent(m);
    ans = LINF;
    
    FOR(i, 0, m) cin >> ent[i];
    sort(ent.begin(), ent.end());
    
    FOR(i, 0, m){
      cin >> x >> y;
      grafo[x].PB(y);
      grafo[y].PB(x);
      dat[i + 1] = ent[i] + dat[i];
    }
    
    d1[a] = 0;
    d2[b] = 0;
    d3[c] = 0;
    bfs(grafo, d1, a);
    bfs(grafo, d2, b);
    bfs(grafo, d3, c);
    
    FOR(i, 1, n + 1){
      if(d1[i] + d2[i] + d3[i] <= m){
        xx = dat[d2[i]];
        xx += dat[d2[i] + d1[i] + d3[i]];
        ans = min(ans, xx);
      }
    }
    
    cout << ans << "\n";
    
  }
  
  return 0;
}