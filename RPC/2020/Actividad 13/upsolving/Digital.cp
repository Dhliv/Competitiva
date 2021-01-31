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
#define MAX 100004

using namespace std;

ll dp[MAX][10][3][10], n;
string num;

void f(int i, int s, int e){
  if((i == n and e == 1) or e == 2){
    FOR(j, 0, 10){
      if(j == s) dp[i][s][e][j] = 1;
      else dp[i][s][e][j] = 0;
    }
    return;
  }
  if(i == n){
    FOR(j, 0, 10) dp[i][s][e][j] = 0;
  }
  if(dp[i][s][e][0] != -1) return;
  
  int mod = s;
  mod += (num[i] - '0');
  if(mod) mod = 1 + (mod - 1)%9;
  
  if(e == 0){
    f(i + 1, s, e);
    f(i + 1, mod, e + 1);
    
    FOR(j, 0, 10) dp[i][s][e][j] = dp[i + 1][s][e][j] + dp[i + 1][mod][e + 1][j];
  }else{
    f(i + 1, mod, e);
    f(i + 1, s, e + 1);
    
    FOR(j, 0, 10) dp[i][s][e][j] = dp[i + 1][mod][e][j] + dp[i + 1][s][e + 1][j];
  }
  
  return;
}

int main(){
  cin >> n >> num;
  memset(dp, -1, sizeof(dp));
  
  f(0, 0, 0);
  
  FOR(i, 0, 9) cout << dp[0][0][0][i] << " ";
  cout << dp[0][0][0][9] << "\n";

  return 0;
}