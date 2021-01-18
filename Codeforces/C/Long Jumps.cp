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

int dp[200000], n;

int f(int i, vector<int> &q){
  if(i >= n) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;
  
  ans = q[i] + f(i + q[i], q);
  
  return ans;
}

int main(){
  int cases, ans;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    vector<int> q(n);
    
    FOR(i, 0, n) cin >> q[i];
    
    memset(dp, -1, sizeof(dp));
    ans = 0;
    
    FOR(i, 0, n) ans = max(ans, f(i, q));
    cout << ans << "\n";
  }
  
  return 0;
}