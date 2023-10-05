#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

int n;
vector<vector<int>> g;

vector<bool> visited;
vector<int> tin, low;
deque<int> artics;
int timer;

void dfs(int v, int p = -1) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  int children=0;
  for (int &to : g[v]) {
    if (to == p) continue;

    if (visited[to]) low[v] = min(low[v], tin[to]);
    else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] >= tin[v] && p != -1){
        artics.PB(v);
      }
      ++children;
    }
  }

  if(p == -1 && children > 1){
    artics.PB(v);
  }
}

void find_cutpoints() {
  timer = 0;
  visited.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) dfs (i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b; cin >> a >> b;
  n = a*b;
  vector<string> board(a); FOR(i, 0, a) cin >> board[i];
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  int r, c;
  int id, idx;
  g.assign(n, {});

  int cnt = 0;

  FOR(i, 0, a){
    FOR(j, 0, b){
      id = i*b + j;
      if(board[i][j] == '.') continue;
      cnt++;
      FOR(k, 0, 4){
        r = i + dr[k];
        c = j + dc[k];

        if(r < 0 or r >= a or c < 0 or c >= b or board[r][c] == '.') continue;
        idx = r*b + c;
        g[id].PB(idx);
        g[idx].PB(id);
      }
    }
  }

  int ans = 2;
  find_cutpoints();
  if(artics.size()) ans = 1;
  if(cnt <= 2) ans = -1;

  cout << ans << "\n";

  return 0;
}