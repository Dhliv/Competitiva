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

using namespace std;

int ans, nds, s, t, n, m, k;
vector<vector<int> > grf;
vector<int> seen;

int bfs(int &ori){
  int x, y;
  FOR(i, 0, nds) seen[i] = INF;
  seen[ori] = 0;
  deque<int> q;
  q.PB(ori);
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grf[x].size()){
      y = grf[x][i];
      if(seen[y] == INF){
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return seen[t];
}

int dfs(int x){
  int y, fl = INF;
  
  FOR(i, 0, grf[x].size()){
    y = grf[x][i];
    if(y == t){
      fl = 1;
      grf[y].PB(x);
      grf[x].erase(grf[x].begin() + i);
      ans++;
      return fl;
    }else if(seen[x] + 1 == seen[y]){
      fl = dfs(y);
      
      if(fl != INF){
        grf[y].PB(x);
        grf[x].erase(grf[x].begin() + i);
        return fl;
      }
    }
  }
  
  return fl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int ax, x;
  cin >> n >> m >> k;
  
  nds = n + m + 2;
  s = 0;
  t = nds - 1;
  grf.resize(nds);
  
  FOR(i, 1, n + 1){
    cin >> ax;
    grf[s].PB(i);
    
    FOR(j, 0, ax){
      cin >> x;
      x += n;
      grf[i].PB(x);
    }
  }
  
  FOR(i, n + 1, t) grf[i].PB(t);
  
  ans = 0;
  seen.resize(nds);
  
  while(bfs(s) != INF){
    while(dfs(s) != INF){}
  }
  
  for(int i = 1; i < n + 1 and k > 0; i++){
    if(bfs(i) != INF){
      dfs(i);
      k--;
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}