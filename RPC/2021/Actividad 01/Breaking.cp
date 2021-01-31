#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF -1000000000
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
#define MAX 10000
 
using namespace std;

ll dp[MAX][101], n;

int f(int i, int k, vector<int> &p, vector<int> &h, vector<int> &pre){
  if(i == n and k <= 0) return 0;
  if(i == n) return MINF;
  if(k <= 0) return pre[i];
  ll &ans = dp[i][k];
  if(ans != -1) return ans;
  
  ans = max(h[i] + f(i + 1, k, p, h, pre), f(i + 1, k - p[i], p, h, pre));
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  int cases, a, b, c, k, s;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> n >> k;
    vector<int> p(n), h(n), pre(n + 1);
    s = 0;
    
    FOR(i, 0, n){
      cin >> p[i] >> b >> c;
      h[i] = max(b, c);
      s += p[i];
    }
    
    FORI(i, n - 1, 0) pre[i] = h[i] + pre[i + 1];
    
    if(s < k) cout << "NO SOLUTION\n";
    else{
      FOR(i, 0, n){
        FOR(j, 0, k + 1) dp[i][j] = -1;
      }
      cout << f(0, k, p, h, pre) << "\n";
    }
  }
  
  return 0;
}