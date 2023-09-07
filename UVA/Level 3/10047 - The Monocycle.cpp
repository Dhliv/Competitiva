#include <bits/stdc++.h>
#define INF INT_MAX
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

struct edge{
  int r, c, dir, col;

  edge(){}
  edge(int r, int c, int dir, int col){
    this->r = r;
    this->c = c;
    this->dir = dir;
    this->col = col;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int COLORS = 5;
  const int DIRS = 4;
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  int r, c, rx, cx, col, d, ri, ci, rf, cf;
  edge e;
  int cases = 0;
  while(cin >> r >> c, r + c){
    if(cases++) cout << "\n";
    cout << "Case #" << cases << "\n";
 
    vector<string> board(r);
    FOR(i, 0, r){
      cin >> board[i];
      FOR(j, 0, c){
        if(board[i][j] == 'S'){
          ri = i;
          ci = j;
        }

        if(board[i][j] == 'T'){
          rf = i;
          cf = j;
        }
      }
    }

    vector<vector<vector<vector<int> > > > dp(r, vector<vector<vector<int> > > (c, vector<vector<int> > (DIRS, vector<int> (COLORS, INF))));
    dp[ri][ci][0][0] = 0;
    deque<edge> q(1, edge(ri, ci, 0, 0));
    while(!q.empty()){
      e = q.F(); q.P_F();

      rx = e.r + dr[e.dir];
      cx = e.c + dc[e.dir];
      col = (e.col + 1)%COLORS;

      if(rx >= 0 and rx < r and cx >= 0 and cx < c and board[rx][cx] != '#'){
        if(dp[rx][cx][e.dir][col] == INF){
          dp[rx][cx][e.dir][col] = 1 + dp[e.r][e.c][e.dir][e.col];
          q.PB(edge(rx, cx, e.dir, col));
        }
      }

      for(int i = -1; i < 2; i += 2){
        d = (e.dir + i + DIRS)%DIRS;
        if(dp[e.r][e.c][d][e.col] != INF) continue;
        dp[e.r][e.c][d][e.col] = 1 + dp[e.r][e.c][e.dir][e.col];
        q.PB(edge(e.r, e.c, d, e.col));
      }
    }

    int mini = INF;
    FOR(i, 0, DIRS) mini = min(mini, dp[rf][cf][i][0]);

    if(mini == INF) cout << "destination not reachable\n";
    else cout << "minimum time = " << mini << " sec\n";
  }
 
  return 0;
}