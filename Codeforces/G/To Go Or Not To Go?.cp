#include <bits/stdc++.h>
#define INF LLONG_MAX
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

vector<vector<ll> > d;
ll x, y, a, b, w, n, m;
ll ac;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(vector<vector<ll> > &s, pair<int, int> ori){
  deque<pair<int, int> > q;
  q.PB(ori);
  while(!q.empty()){
    x = q.F().f;
    y = q.F().s;
    q.P_F();
    
    FOR(i, 0, 4){
      a = x + dx[i];
      b = y + dy[i];
      if(a >= 0 and a < n and b >= 0 and b < m and d[a][b] != -1){
        ac = w + s[x][y];
        
        if(s[a][b] == INF){
          s[a][b] = ac;
          q.PB(MP(a, b));
        }
      }
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll c, x, y, a, b, mini1, mini2, ans;
  cin >> n >> m >> w;
  d.resize(n, vector<ll> (m));
  deque<pair<ll, ll> > pr, q;
  
  FOR(i, 0, n){
    FOR(j, 0, m){
      cin >> d[i][j];
      if(d[i][j] > 0) pr.PB(MP(i, j));
    }
  }
  
  vector<vector<ll> > s1(n, vector<ll> (m, INF)), s2(n, vector<ll> (m, INF));
  s1[0][0] = 0;
  s2[n - 1][m - 1] = 0;
  bfs(s1, MP(0, 0));
  bfs(s2, MP(n - 1, m - 1));
  
  mini1 = mini2 = ans = INF;
  
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(d[i][j] <= 0) continue;
      if(s1[i][j] != INF) mini1 = min(mini1, s1[i][j] + d[i][j]);
      if(s2[i][j] != INF) mini2 = min(mini2, s2[i][j] + d[i][j]);
    }
  }
  
  if(mini1 != INF and mini2 != INF) ans = mini2 + mini1;
  if(s2[0][0] != INF) ans = min(ans, s2[0][0]);
  
  if(ans == INF) cout << "-1\n";
  else cout << ans << "\n";
  
  return 0;
}