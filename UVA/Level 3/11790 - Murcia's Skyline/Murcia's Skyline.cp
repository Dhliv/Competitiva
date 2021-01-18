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

vector<int> dp1, dp;

int lis(int i, int &e, deque<int> &w, deque<int> &q){
  if(i == 0) return w[i];
  if(e and dp1[i] != -1) return dp1[i];
  if(!e and dp[i] != -1) return dp[i];
  
  int maxi = 0, ans = w[i];
  
  if(e){
    FOR(j, 0, i){
      if(q[j] > q[i]) maxi = max(maxi, lis(j, e, w, q));
    }
  }else{
    FOR(j, 0, i){
      if(q[j] < q[i]) maxi = max(maxi, lis(j, e, w, q));
    }
  }
  
  if(e) return dp1[i] = ans + maxi;
  else return dp[i] = ans + maxi;
}

int main(){
  int n, cases, a, b, ASC = 0, DESC = 1;
  cin >> cases;
  
  FOR(ab, 1, cases + 1){
    cout << "Case " << ab << ". ";
    cin >> n;
    deque<int> w(n + 1), q(n + 1);
    
    FOR(i, 0, n) cin >> q[i];
    FOR(i, 0, n) cin >> w[i];
    
    dp.assign(n + 1, -1);
    q[n] = INF;
    w[n] = 0;
    a = lis(n, ASC, w, q);
    
    dp1.assign(n + 1, -1);
    q[n] = MINF;
    b = lis(n, DESC, w, q);
    
    if(a >= b) cout << "Increasing (" << a << "). Decreasing (" << b << ").\n";
    else cout << "Decreasing (" << b << "). Increasing (" << a << ").\n";
  }
  
  return 0;
}