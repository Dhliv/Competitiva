#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, x, y, xc, yc, zc, z;

  while(t--){
    cin >> n >> x >> y;
    xc = n/x;
    yc = n/y;
    z = (x*y)/__gcd(x, y);
    zc = n/z;

    ll ans = 0;
    ll val = n - (xc - zc);
    ans = (n*(n + 1))/2 - (val*(val + 1))/2;
    val = yc - zc;
    ans -= (val*(val + 1))/2;

    cout << ans << "\n";
  }

  return 0;
}