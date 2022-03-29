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

ll f(ll a, ll b, ll c, ll n){
  if(a == 0) return (b == -1 ? b*n : 0);

  if(a >= c)
    return (((a/c)*n*(n + 1))/2 + f(a%c, b, c, n));

  ll m = (a*n + b)/c;
  return (n*m - f(c, -b - 1, a, m));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll a, b, c, n, ans;

  FOR(ab, 0, t){
    cin >> a >> c >> n;
    b = 0;
    ans = (a*n*(n + 1))/2;

    ans -= c*f(a, b, c, n);

    cout << ans << "\n";
  }

  return 0;
}
