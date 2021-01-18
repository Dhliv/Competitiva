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
#define MAX 2002

using namespace std;

int m, d, mod = 1e9 + 7;
int dp[MAX][MAX][2][2];

int f(int i, int e, int a1, int a2, string &n, string &b){
  if(i == n.size() and e == 0) return 1;
  if(i == n.size()) return 0;
  if(dp[i][e][a1][a2] != -1) return dp[i][e][a1][a2];
  
  int lim, n1, n2, res = 0, ne = e*10, inf;
  if(a1 and a2){
    lim = 9;
    inf = 0;
  }else if(a1 and a2 == 0){
    lim = 9;
    inf = n[i] - '0';
  }else if(a1 == 0 and a2 == 1){
    lim = b[i] - '0';
    inf = 0;
  }else{
    inf = n[i] - '0';
    lim = b[i] - '0';
  }
  
  if(i%2 == 0){
    FOR(j, inf, lim + 1){
      n1 = a1;
      n2 = a2;
      if(n1 == 0 and j < lim) n1 = 1;
      if(n2 == 0 and j > inf) n2 = 1;

      if(j != d) res = (res + f(i + 1, (ne + j)%m, n1, n2, n, b)%mod)%mod;
    }
  }else{
    if(a1 and a2) res = f(i + 1, (ne + d)%m, a1, a2, n, b)%mod;
    else if(a1 and a2 == 0 and d >= inf){
      n1 = a1;
      n2 = a2;
      if(d > inf) n2 = 1;
      
      res = f(i + 1, (ne + d)%m, n1, n2, n, b)%mod;
    }else if(a1 == 0 and a2 and d <= lim){
      n1 = a1;
      n2 = a2;
      if(d < lim) n1 = 1;
      
      res = f(i + 1, (ne + d)%m, n1, n2, n, b)%mod;
    }
    else if(d >= inf and d <= lim){
      n1 = a1;
      n2 = a2;
      if(d < lim) n1 = 1;
      if(d > inf) n2 = 1;
      
      res = f(i + 1, (ne + d)%m, n1, n2, n, b)%mod;
    }
  }
  
  return dp[i][e][a1][a2] = res;
}

int main(){
  string a, b;
  int res;
  
  cin >> m >> d;
  cin >> a >> b;
  
  memset(dp, -1, sizeof(dp));
  res = f(0, 0, 0, 0, a, b)%mod;
  
  cout << res << "\n";
  
  return 0;
}