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
 
vector<ll> s, id, v, tagged;
vector<vector<int> > g[2];
deque<int> ts;
int tag;
 
void dfs(int &gr, int x){
  v[x] = 1;
  for(auto i : g[gr][x]){
    if(!v[i]) dfs(gr, i);
  }
  
  if(gr == 0) ts.PF(x);
  else{
    id[x] = tag;
    tagged[tag]++;
  }
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, m, x, y, z = 0, u = 1;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> m;
    s.assign(n + 1, 0);
    v.assign(n + 1, 0);
    id.assign(n + 1, 0);
    tagged.assign(n + 1, 0);
    FOR(i, 0, 2) g[i].assign(n + 1, {});
    tag = 1;
    s[1] = 1;
    
    FOR(i, 0, m){
      cin >> x >> y;
      g[0][x].PB(y);
      g[1][y].PB(x);
      if(x == y) s[x] = INF;
    }
    
    FOR(i, 1, n + 1){
      if(!v[i]) dfs(z, i);
    }
    FOR(i, 1, n + 1) v[i] = 0;
    
    while(!ts.empty()){
      if(!v[ts.F()]){
        dfs(u, ts.F());
        tag++;
      }
      ts.P_F();
    }
  
    FOR(i, 1, n + 1) v[i] = 0;
    dfs(z, 1);
    
    while(!ts.empty()){
      x = ts.F();
      ts.P_F();
      
      if(tagged[id[x]] > 1) s[x] = INF;
      
      FOR(i, 0, g[0][x].size()){
        y = g[0][x][i];
        if(s[x] == INF) s[y] = INF;
        else{
          s[y] += s[x];
          if(s[y] >= INF) s[y] = INF;
          else if(s[y] > 5) s[y] = 5;
        }
      }
    }
    
    FOR(i, 1, n + 1){
      if(!v[i]) cout << "0 ";
      else if(s[i] == 1) cout << 1 << " ";
      else if(s[i] < INF) cout << "2 ";
      else cout << "-1 ";
    }
    
    cout << "\n";
  }
 
  return 0;
}