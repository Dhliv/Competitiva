#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
#define MAX 1001
 
using namespace std;

int dp[MAX][2][MAX], p[MAX][2];
int n, m, x, y;

int f(int i, bool color, int acum){
  if(i == m and acum >= x and acum <= y) return 0;
  else if(i == m) return MAX*MAX;

  int &ans = dp[i][color][acum];
  if(ans != -1) return ans;

  ans = 0;
  bool otherColor = 1 - color;
  if(acum < x) ans = p[i][otherColor] + f(i + 1, color, acum + 1);
  else if(acum < y){
    ans = min(p[i][otherColor] + f(i + 1, color, acum + 1), p[i][color] + f(i + 1, otherColor, 1));
  }else ans = p[i][color] + f(i + 1, otherColor, 1);

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> x >> y;
  string s;

  memset(dp, -1, sizeof(dp));
  memset(p, 0, sizeof(p));

  FOR(i, 0, n){
    cin >> s;
    FOR(j, 0, m){
      if(s[j] == '.') p[j][0]++;
      else p[j][1]++;
    }
  }

  cout << min(p[0][1] + f(1, 0, 1), p[0][0] + f(1, 1, 1)) << "\n";

  return 0;
}
