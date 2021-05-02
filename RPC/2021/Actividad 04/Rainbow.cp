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

ll mod = 998244353;
ll dp[100005][2][2][2][10], n;

ll f(int i, int f1, int f2, int e, int l, string &low, string &up){
  if(i == n) return 1;
  ll &ans = dp[i][f1][f2][e][l];
  if(ans != -1) return ans;
  
  int lim, inf, nf1, nf2, ne;
  lim = f2 ? 9 : up[i] - '0';
  inf = f1 ? 0 : low[i] - '0';
  
  ans = 0;
  FOR(j, inf, lim + 1){
    nf1 = f1;
    nf2 = f2;
    ne = e;
    if(!f1 and j > inf) nf1 = 1;
    if(!f2 and j < lim) nf2 = 1;
    
    if(ne){
      if(l != j) ans += f(i + 1, nf1, nf2, ne, j, low, up);
    }else{
      if(!e and j > 0) ne = 1;
      ans += f(i + 1, nf1, nf2, ne, j, low, up);
    }
  }
  
  ans %= mod;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string a, b, c;
  cin >> a >> b;
  
  int x = b.size() - a.size();
  c = "";
  
  FOR(i, 0, x) c.PB('0');
  a = c + a;
  n = b.size();
  
  memset(dp, -1, sizeof(dp));
  
  cout << f(0, 0, 0, 0, 0, a, b) << "\n";

  return 0;
}