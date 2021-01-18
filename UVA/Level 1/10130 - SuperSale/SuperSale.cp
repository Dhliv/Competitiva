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

int dp[1001][31], n;

int f(int i, int c, deque<int> &p, deque<int> &w){
  if(i == n or c == 0) return 0;
  int &ans = dp[i][c];
  if(ans != -1) return ans;
  
  int maxi;
  maxi = f(i + 1, c, p, w);
  if(c >= w[i]) maxi = max(maxi, p[i] + f(i + 1, c - w[i], p, w));
  
  return ans = maxi;
}

int main(){
  int cases, g, v, w, c, ans;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    deque<int> p(n), w(n);
    
    FOR(i, 0, n){
      cin >> p[i];
      cin >> w[i];
    }
    n = p.size();
    
    cin >> g;
    ans = 0;
    memset(dp, -1, sizeof(dp));
    FOR(i, 0, g){
      cin >> c;
      ans += f(0, c, p, w);
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}