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

int m, n;
int dp[100][10];

int f(int c, int r, vector<vector<int> > &q){
  if(c == n) return 0;
  int &ans = dp[c][r];
  if(ans != -1) return ans;
  
  ans = q[r][c];
  ans += min({f(c + 1, (r - 1 + m)%m, q), f(c + 1, r, q), f(c + 1, (r + 1)%m, q)});
  
  return ans;
}

void sol(int c, int r, vector<vector<int> > &q){
  if(c + 1 == n) return;
  
  vector<pair<int, int> > s(3);
  int a = dp[c + 1][(r - 1 + m)%m], b = dp[c + 1][r], ans = dp[c][r] - q[r][c];
  s[0] = MP((r - 1 + m)%m, a);
  s[1] = MP(r, b);
  s[2] = MP((r + 1)%m, dp[c + 1][(r + 1)%m]);
  sort(s.begin(), s.end());
  
  FOR(i, 0, s.size()){
    if(ans == s[i].s){
      cout << " " << s[i].f + 1;
      sol(c + 1, s[i].f, q);
      break;
    }
  }
  
  return;
}

int main(){
  int mini, ini, d;
  
  while(cin >> m >> n){
    vector<vector<int> > q(m, vector<int> (n));
    
    FOR(i, 0, m){
      FOR(j, 0, n) cin >> q[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    mini = INF;
    
    FOR(i, 0, m){
      d = f(0, i, q);
      if(mini > d){
        mini = d;
        ini = i;
      }
    }
    cout << ini + 1;
    sol(0, ini, q);
    cout << "\n" << mini << "\n";
  }
  
  return 0;
}