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

int n, LIS;
int dp1[10][11][10][2][2][2];
int dp[10][11][10][2][2][2];

int lis(int i, int d, int s, int e, int a1, int a2, string &a, string &b){
  if(i == n) return s;
  if(dp1[i][d][s][e][a1][a2] != -1) return dp1[i][d][s][e][a1][a2];
  
  int lim, inf, n1, n2, maxi = 0, ne;
  inf = a1 ? 0 : (a[i] - '0');
  lim = a2 ? 9 : (b[i] - '0');
  
  FOR(j, inf, lim + 1){
    n1 = a1;
    n2 = a2;
    ne = e;
    if(a1 == 0 and j > inf) n1 = 1;
    if(a2 == 0 and j < lim) n2 = 1;
    if(e == 0 and j > 0) ne = 1;
    
    if(ne and (j + 1) > d) maxi = max(maxi, lis(i + 1, j + 1, s + 1, ne, n1, n2, a, b));
    maxi = max(maxi, lis(i + 1, d, s, ne, n1, n2, a, b));
  }
  
  return dp1[i][d][s][e][a1][a2] = maxi;
}

int f(int i, int d, int s, int e, int a1, int a2, string &a, string &b){
  if(i == n and s == LIS) return 1;
  if(i == n) return 0;
  if(dp[i][d][s][e][a1][a2] != -1) return dp[i][d][s][e][a1][a2];
  
  int lim, inf, n1, n2, res = 0, ne;
  inf = a1 ? 0 : (a[i] - '0');
  lim = a2 ? 9 : (b[i] - '0');
  
  FOR(j, inf, lim + 1){
    n1 = a1;
    n2 = a2;
    ne = e;
    if(a1 == 0 and j > inf) n1 = 1;
    if(a2 == 0 and j < lim) n2 = 1;
    if(e == 0 and j != 0) ne = 1;
    
    if(ne and (j + 1) > d) res += f(i + 1, j + 1, s + 1, ne, n1, n2, a, b);
    res += f(i + 1, d, s, ne, n1, n2, a, b);
  }
  
  return dp[i][d][s][e][a1][a2] = res;
}

int main(){
  int cases;
  string a, b, ax;
  cin >> cases;
  
  FOR(aid, 0, cases){
    cin >> a >> b;
    cout << "Case " << aid + 1 << ": ";
    n = b.size();
    ax = "";
    FOR(i, 0, n - a.size()) ax += "0";
    a = ax + a;
    
    memset(dp1, -1, sizeof(dp1));
    LIS = lis(0, 0, 0, 0, 0, 0, a, b);
    
    memset(dp, -1, sizeof(dp));
    cout << LIS << " " << f(0, 0, 0, 0, 0, 0, a, b) << "\n";
  }
  
  return 0;
}