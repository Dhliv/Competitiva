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
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
 
using namespace std;

ll dp[17][17][2][2][2];

ll f(int i, int bi, bool menor, bool zero, bool mayorMitadDerecha, string &a){
  if(i > bi){
    if(!menor and mayorMitadDerecha) return 0;

    return 1;
  }

  ll &ans = dp[i][bi][menor][zero][mayorMitadDerecha];
  if(ans != -1) return ans;

  ans = 0;
  int maxi = menor ? 9 : a[i] - '0';
  bool nm, nz, nmd;

  FOR(j, 0, maxi + 1){
    nm = menor | (j < maxi);
    nz = zero | (j > 0);
    nmd = (j > a[bi] - '0');

    if(!nz){
      ans += f(i + 1, bi, nm, nz, mayorMitadDerecha, a);
    }else if(bi == i){
      ans += f(i + 1, bi, nm, nz, mayorMitadDerecha, a);
    }else{
      if(j == a[bi] - '0'){
        ans += f(i + 1, bi - 1, nm, nz, mayorMitadDerecha, a);
      }else ans += f(i + 1, bi - 1, nm, nz, nmd, a);
    }
  }

  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, id = 1; cin >> t;

  while(t--){
    cout << "Case " << id++ << ": ";
    ll a, b, ans; cin >> a >> b;
    if(a > b) swap(a, b);
    string x, y;
    y = to_string(b);
    memset(dp, -1, sizeof(dp));
    ans = f(0, y.size() - 1, 0, 0, 0, y);

    if(a > 0){
      a--;
      x = to_string(a);
      memset(dp, -1, sizeof(dp));
      ans -= f(0, x.size() - 1, 0, 0, 0, x);
    }

    cout << ans << "\n";
  }

  return 0;
}