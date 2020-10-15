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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main() {
  ll n, wei;
  cin >> n >> wei;
  ll dp[n][wei+1];
  vector<int> pesos(n), valores(n);
  
  FOR(i, 0, n)
    cin >> pesos[i] >> valores[i];
    
  FOR(i, 0, wei+1){
    if(pesos[0] <= i)
      dp[0][i] = valores[0];
    else
      dp[0][i] = 0;
  }
  
  FOR(i, 1, n){
    FOR(j, 0, wei+1){
      if(pesos[i] <= j){
        dp[i][j] = max(dp[i-1][j], valores[i] + dp[i-1][j - pesos[i]]);
      }else
        dp[i][j] = dp[i-1][j];
    }
  }
  
  cout << dp[n-1][wei] << "\n";

  return 0;
}