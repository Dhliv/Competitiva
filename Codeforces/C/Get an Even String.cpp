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
#define MAX 200000
 
using namespace std;
 
int dp[MAX][26][2];
string s;
int n;
 
int f(int i, int lc, int state) {
  if(i == n){
    if(state) return n;
    return 0;
  }
 
  int &ans = dp[i][lc][state];
  if(ans != -1) return ans;
 
  ans = f(i + 1, lc, state) + 1;
  if(state){
    if(s[i] - 'a' == lc) ans = min(ans, f(i + 1, 0, 0));
  }else ans = min(ans, f(i + 1, s[i] - 'a', 1));
 
  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t; cin >> t;
 
  FOR(ab, 0, t) {
    cin >> s;
    n = s.size();
 
    FOR(i, 0, n){
      FOR(j, 0, 26){
        FOR(k, 0, 2) dp[i][j][k] = -1;
      }
    }
 
    cout << f(0, 0, 0) << "\n";
  }
 
  return 0;
}