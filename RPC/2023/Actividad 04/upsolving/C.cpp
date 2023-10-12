#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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

ll n, m, k;
vector<vector<ll> > grid;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void build(vector<vector<ll> > &grid){
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(i) grid[i][j] += grid[i - 1][j];
      if(j) grid[i][j] += grid[i][j - 1];
      if(i and j) grid[i][j] -= grid[i - 1][j - 1];
    }
  }
}

bool able(int s){
  ll val;
  vector<vector<ll> > sum(n, vector<ll> (m));
  deque<pair<int, int> > q;
  pair<int, int> p;
  int x, y;
  FOR(i, s - 1, n){
    FOR(j, s - 1, m){
      val = grid[i][j];
      if(i >= s) val -= grid[i - s][j];
      if(j >= s) val -= grid[i][j - s];
      if(i >= s and j >= s) val += grid[i - s][j - s];

      if(val) continue;
      sum[i][j] = 1;
      q.PB(MP(i, j));
      break;
    }

    if(q.size()) break;
  }

  while(!q.empty()){
    p = q.F();
    q.P_F();

    FOR(i, 0, 4){
      x = p.f + dr[i];
      y = p.s + dc[i];

      if(x < s - 1 or x >= n or y < s - 1 or y >= m or sum[x][y]) continue;
      val = grid[x][y];
      if(x >= s) val -= grid[x - s][y];
      if(y >= s) val -= grid[x][y - s];
      if(x >= s and y >= s) val += grid[x - s][y - s];
      if(val) continue;
      sum[x][y] = 1;
      q.PB(MP(x, y));
    }
  }

  build(sum);

  int cnt = 0;
  FOR(i, 0, n){
    FOR(j, 0, m){
      x = min(n - 1, i + s - 1);
      y = min(m - 1, j + s - 1);
      val = sum[x][y];
      if(i) val -= sum[i - 1][y];
      if(j) val -= sum[x][j - 1];
      if(i and j) val += sum[i - 1][j - 1];
      if(val == 0) cnt++;
    }
  }

  return cnt == k;
}

int bs(){
  int l = 1, r = min(n, m), mid;

  while(l <= r){
    mid = (l + r)/2;
    if(able(mid)) l = mid + 1;
    else r = mid - 1;
  }

  if(able(l)) return l;
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  grid.assign(n, vector<ll> (m));
  int x, y;
  FOR(i, 0, k){
    cin >> x >> y;
    grid[x - 1][y - 1] = 1;
  }

  int cnt = 1;
  vector<vector<int> > sn(n, vector<int> (m, 0));
  deque<pair<int, int> > q;
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(grid[i][j]) continue;
      q.PB(MP(i, j));
      sn[i][j] = 1;
      break;
    }
    if(q.size()) break;
  }

  pair<int, int> p;
  while(!q.empty()){
    p = q.F();
    q.P_F();

    FOR(i, 0, 4){
      x = p.f + dr[i];
      y = p.s + dc[i];
      if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] or sn[x][y]) continue;
      cnt++;
      sn[x][y] = 1;
      q.PB(MP(x, y));
    }
  }

  if(cnt + k != n*m){
    cout << "-1\n";
    return 0;
  }

  build(grid);

  int ans = bs();
  cout << (ans ? ans : -1) << "\n";

  return 0;
}