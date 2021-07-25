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
vector<vector<int> > g[2], ans;
deque<int> ts;
vector<int> v;

void dfs(int &gr, int x){
  int y;
  v[x] = 1;
  
  for(auto i: g[gr][x]){
    if(!v[i]) dfs(gr, i);
  }
  
  if(gr == 0) ts.PF(x);
  else ans[tag].PB(x);
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, x, y, ab = 0, z = 0, u = 1;
  string xs, ys;
  while(cin >> n >> m, n + m){
    if(ab++) cout << "\n";
    map<string, int> id;
    vector<string> names(n);
    
    g[0].assign(n, {});
    g[1].assign(n, {});
    ans.assign(n, {});
    v.assign(n, {});
    
    FOR(i, 0, m){
      cin >> xs >> ys;
      
      if(id.find(xs) == id.end()){
        x = id.size();
        id[xs] = x;
        names[x] = xs;
      }else x = id[xs];
      
      if(id.find(ys) == id.end()){
        y = id.size();
        id[ys] = y;
        names[y] = ys;
      }else y = id[ys];
      
      g[0][x].PB(y);
      g[1][y].PB(x);
    }
    
    FOR(i, 0, n) if(!v[i]) dfs(z, i);
    
    FOR(i, 0, n) v[i] = 0;
    
    tag = 0;
    while(ts.size()){
      if(!v[ts.F()]){
        dfs(u, ts.F());
        tag++;
      }
      ts.P_F();
    }
    
    cout << "Calling circles for data set " << ab << ":\n";
    FOR(i, 0, tag){
      cout << names[ans[i][0]];
      FOR(j, 1, ans[i].size()) cout << ", " << names[ans[i][j]];
      cout << "\n";
    }
  }
 
  return 0;
}