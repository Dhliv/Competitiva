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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int n, m, t;

ll c(int n, int k){
  __int128 res = 1;
  __int128 l = 2;

  FORI(i, n, max(k, n - k) + 1) res *= i;

  while(l <= min(k, n - k)) res /= l++;

  return (ll) res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll ans = 0;
  cin >> n >> m >> t;

  FOR(i, 4, n + 1){
    if(t - i <= m and t - i > 0){
      //cout << n << "C" << i << " = " << c(n, i) << "\n";
      //cout << m << "C" << t - i << " = " << c(m, t - i) << "\n";
      ans += c(n, i)*c(m, t - i);
    }
  }

  cout << ans << "\n";

  return 0;
}