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

ll dp[19][2][2][2][10];

ll f(int i, bool f1, bool f2, bool e, int d, string &a, string &b){
  if(i == a.size()) return 1;
  ll &ans = dp[i][f1][f2][e][d];
  if(ans != -1) return ans;

  int nf1, nf2, ne, up, dw;
  up = f2 ? 9 : b[i] - '0';
  dw = f1 ? 0 : a[i] - '0';

  ans = 0;
  FOR(j, dw, up + 1){
    nf1 = f1;
    nf2 = f2;
    ne = e;
    if(j > dw) nf1 = 1;
    if(j < up) nf2 = 1;
    if(j != 0) ne = 1;

    if(ne){
      if(d != j) ans += f(i + 1, nf1, nf2, ne, j, a, b);
    }else ans += f(i + 1, nf1, nf2, ne, j, a, b);
  }

  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a, b, c; cin >> a >> b;

  c = "";
  FOR(i, 0, b.size() - a.size()) c.PB('0');
  a = c + a;

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0, 0, 0, 0, a, b) << "\n";

  return 0;
}
