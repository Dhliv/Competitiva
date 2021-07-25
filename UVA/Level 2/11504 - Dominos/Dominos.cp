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

vector<vector<int> > g;
deque<int> ts;
vector<int> v;

void dfs(int &id, int x){
  v[x] = 1;
  
  for(auto y: g[x]){
    if(!v[y]) dfs(id, y);
  }
  
  if(id == 0) ts.PF(x);
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, m, x, y, ans, z = 0, u = 1;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> m;
    n++;
    g.assign(n, {});
    v.assign(n, 0);
    
    FOR(i, 0, m){
      cin >> x >> y;
      g[x].PB(y);
    }
    
    FOR(i, 1, n) if(!v[i]) dfs(z, i);
    
    FOR(i, 1, n) v[i] = 0;
    
    ans = 0;
    while(!ts.empty()){
      if(!v[ts.F()]){
        ans++;
        dfs(u, ts.F());
      }
      ts.P_F();
    }
    
    cout << ans << "\n";
  }
 
  return 0;
}