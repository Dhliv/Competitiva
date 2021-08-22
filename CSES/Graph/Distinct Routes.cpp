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
#define MAX 502
 
using namespace std;

int ans;
vector<vector<int> > g(MAX), fls(MAX, vector<int> (MAX)), gans(MAX), flans(MAX, vector<int> (MAX));
vector<int> s(MAX);
deque<int> res;

bool bfs(int &ori, int &t, int &id){
  FOR(i, 0, s.size()) s[i] = INF;
  deque<int> q;
  q.PB(ori);
  int x;
  s[ori] = 0;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(auto y: (id == 0 ? g[x] : gans[x])){
      if(s[y] == INF and (id == 0 ? fls[x][y] : flans[x][y])){
        s[y] = s[x] + 1;
        q.PB(y);
      }
    }
  }

  return s[t] != INF;
}

int dfs(int x, int &t){
  int fl = INF;

  for(auto y: g[x]){
    if(y == t and fls[x][y]){
      fls[x][y]--;
      fls[y][x]++;

      flans[x][y]++;
      if(flans[y][x]) flans[y][x]--;
      ans++;
      return 1;
    }else if(s[x] + 1 == s[y] and fls[x][y]){
      fl = dfs(y, t);

      if(fl != INF){
        fls[x][y]--;
        fls[y][x]++;
        flans[x][y]++;
        if(flans[y][x]) flans[y][x]--; 
        return fl;
      }
    }
  }

  return fl;
}

int imp(int x, int &sr){
  int fl = INF;
  for(int y: gans[x]){
    if(y == sr and flans[x][y]){
      flans[x][y]--;
      res.PB(x);
      return 1;
    }
    if(s[x] + 1 == s[y] and flans[x][y]){
      fl = imp(y, sr);

      if(fl != INF){
        flans[x][y]--;
        res.PF(x);
        return fl;
      }
    }
  }

  return INF;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, sr, t, x, y, z = 0, u = 1;
  cin >> n >> m;

  sr = 0;
  t = n + 1;

  FOR(i, 0, m){
    cin >> x >> y;
    if(!fls[x][y]){
      g[x].PB(y);
      gans[x].PB(y);
    }
    if(!fls[y][x]){
      g[y].PB(x);
      gans[y].PB(x);
    }
    fls[x][y] = 1;
  }

  fls[sr][1] = fls[n][t] = m + 1;
  flans[sr][1] = flans[n][t] = m + 1;
  g[sr].PB(1);
  g[n].PB(t);
  g[1].PB(sr);
  g[t].PB(n);
  gans[sr].PB(1);
  gans[n].PB(t);
  gans[1].PB(sr);
  gans[t].PB(n);

  ans = 0;
  while(bfs(sr, t, z)){
    while(dfs(sr, t) != INF){}
  }

  cout << ans << "\n";
  while(bfs(sr, t, u)){
    imp(sr, t);

    res.P_F();
    cout << res.size() << "\n";
    while(!res.empty()){
      cout << res.F() << " ";
      res.P_F();
    }
    cout << "\n";
  }
  
  return 0;
}
