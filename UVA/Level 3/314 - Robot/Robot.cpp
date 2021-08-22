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

  int n, m, x, y, xf, yf, h, hf, ans;
  string face;
  pair<int, int> ori, dest;
  vector<int> dir(26);
  dir['w' - 'a'] = 0;
  dir['n' - 'a'] = 1;
  dir['e' - 'a'] = 2;
  dir['s' - 'a'] = 3;
  static int dx[4] = {-1, 0, 1, 0};
  static int dy[4] = {0, -1, 0, 1};
  static int ch[2] = {3, 1};

  while(cin >> n >> m, n + m){
    vector<vector<int> > d(n, vector<int> (m));
    vector<vector<vector<int> > > s(n, vector<vector<int> > (m, vector<int> (4, INF)));
    FOR(i, 0, n){
      FOR(j, 0, m) cin >> d[i][j];
    }

    cin >> x >> y;
    ori = MP(x, y);
    cin >> x >> y;
    dest = MP(x, y);
    cin >> face;
    deque<pair<pair<int, int>, int> > q;
    q.PB(MP(ori, dir[face[0] - 'a']));
    s[ori.f][ori.s][q.F().s] = 0;

    while(!q.empty()){
      x = q.F().f.f;
      y = q.F().f.s;
      h = q.F().s;
      q.P_F();

      FOR(i, 1, 4){
        xf = x + dy[h]*i;
        yf = y + dx[h]*i;
        if(xf < 1 or xf >= n or yf < 1 or yf >= m) break;
        if(d[xf][yf] or d[xf - 1][yf] or d[xf][yf - 1] or d[xf - 1][yf - 1]) break;
        if(s[xf][yf][h] != INF) continue;
        s[xf][yf][h] = 1 + s[x][y][h];
        q.PB(MP(MP(xf, yf), h));
      }

      FOR(i, 0, 2){
        hf = (h + ch[i])%4;
        if(s[x][y][hf] == INF){
          s[x][y][hf] = 1 + s[x][y][h];
          q.PB(MP(MP(x, y), hf));
        }
      }
    }

    ans = INF;
    FOR(i, 0, 4) ans = min(ans, s[dest.f][dest.s][i]);
    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";
  }

  return 0;
}