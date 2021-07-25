#include <bits/stdc++.h>
#define INF 10000000
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
 
using namespace std;

int tag;
vector<vector<int> > g[2];
vector<int> v;
deque<int> ts;

void dfs(int &gr, int x){
  v[x] = 1;
  
  for(auto y: g[gr][x]){
    if(!v[y]) dfs(gr, y);
  }
  
  if(!(gr & 1)) ts.PF(x);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, x, y, k, z = 0, u = 1;
  
  while(cin >> n >> m, n + m){
    n++;
    g[0].assign(n, {});
    g[1].assign(n, {});
    v.assign(n, 0);
    
    FOR(i, 0, m){
      cin >> x >> y >> k;
      g[0][x].PB(y);
      g[1][y].PB(x);
      
      if(k & 2){
        g[1][x].PB(y);
        g[0][y].PB(x);
      }
    }
    
    FOR(i, 1, n) if(!v[i]) dfs(z, i);
    FOR(i, 1, n) v[i] = 0;
    
    tag = 0;
    while(!ts.empty()){
      if(!v[ts.F()]){
        dfs(u, ts.F());
        tag++;
      }
      ts.P_F();
    }
    
    cout << (tag == 1 ? 1 : 0) << "\n";
  }
 
  return 0;
}