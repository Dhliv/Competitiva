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
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  pair<int, int> ini, dest, x, y;
  string a;
  cin >> n >> m;

  vector<vector<int> > g(n, vector<int> (m)), s(n, vector<int> (m, INF));
  vector<vector<pair<int, int> > > ans(n, vector<pair<int, int> > (m));

  FOR(i, 0, n){
    cin >> a;
    FOR(j, 0, m){
      if(a[j] != '#') {
        g[i][j] = 1;
        if(a[j] == 'A') ini = MP(i, j);
        else if(a[j] == 'B') dest = MP(i, j);
      }
    }
  }

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  s[ini.f][ini.s] = 0;
  deque<pair<int, int> > q;
  q.PB(ini);

  while(!q.empty()){
    x = q.F();
    q.P_F();

    FOR(i, 0, 4){
      y.f = x.f + dy[i];
      y.s = x.s + dx[i];

      if(0 <= y.f and y.f < n and 0 <= y.s and y.s < m and g[y.f][y.s] and s[y.f][y.s] == INF){
        s[y.f][y.s] = s[x.f][x.s] + 1;
        ans[y.f][y.s] = x;
        q.PB(y);
      }
    }
  }

  if(s[dest.f][dest.s] != INF){
    cout << "YES\n" << s[dest.f][dest.s] << "\n";
    string res = "";

    x = dest;
    while(x != ini){
      y = ans[x.f][x.s];

      if(y.f == x.f){
        if(y.s < x.s) res.PB('R');
        else res.PB('L');
      }else{
        if(x.f < y.f) res.PB('U');
        else res.PB('D');
      }

      x = y;
    }

    FORI(i, res.size() - 1, 0) cout << res[i];
    cout << "\n";
  }else cout << "NO\n";
  
  return 0;
}
