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
#define MAX 1425
#define N_MAX 1016026

using namespace std;

const ld EPSILON = 0.0000001;

int hor(ll num, ll nivel){
  return (num - ((nivel + 1)*nivel)/2 - 1)*2 + MAX - 1 - nivel;
}

int dx[2] = {-1, -1};
int dy[2] = {-1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int COLS = MAX*2 - 1;
  vector<vector<ll> > mtr(MAX, vector<ll> (COLS));
  vector<vector<ll> > dp(MAX, vector<ll> (COLS, -1));

  ll sum, num = 1;
  vector<int> lev(N_MAX, 0);
  int col = COLS/2;
  int x, y;
  FOR(i, 0, MAX){
    FOR(j, 0, i + 1){
      lev[num] = i;
      mtr[i][col + 2*j] = num*num;
      num++;
    }
    col--;
  }

  FOR(i, 0, MAX){
    FOR(j, 0, COLS){
      dp[i][j] = mtr[i][j];
      if(i - 2 >= 0) dp[i][j] -= dp[i - 2][j];
      FOR(k, 0, 2){
        x = i - 1;
        y = j + dy[k];

        if(x < 0 or y < 0 or y >= COLS) continue;
        dp[i][j] += dp[x][y];
      }

    }
  }

  int t; cin >> t;
  pair<int, int> ax;
  ll ans, n, nivel;
  while(t--){
    cin >> n;
    x = lev[n];
    y = hor(n, x);

    cout << dp[x][y] << "\n";
  }
 
  return 0;
}