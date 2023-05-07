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
#define MAX 1001

using namespace std;

const ld EPSILON = 0.0000001;
ll grafo[MAX][MAX];
int sn[MAX][MAX];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

ll dfs(int x, int y){
  sn[x][y] = 1;
  ll ans = grafo[x][y];
  int nx, ny;

  FOR(i, 0, 4){
    nx = x + dx[i];
    ny = y + dy[i];

    if(nx < 0 or nx > n or ny < 0 or ny > m) continue;
    if(grafo[nx][ny] == 0 or sn[nx][ny]) continue;
    ans += dfs(nx, ny);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll ans;

  while(t--){
    cin >> n >> m;
    FOR(i, 0, n){
      FOR(j, 0, m){
        cin >> grafo[i][j];
        sn[i][j] = 0;
      }
    }

    ans = 0;
    FOR(i, 0, n){
      FOR(j, 0, m){
        if(grafo[i][j] == 0 or sn[i][j]) continue;
        ans = max(ans, dfs(i, j));
      }
    }

    cout << ans << "\n";
  }
 
  return 0;
}