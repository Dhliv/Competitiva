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
#define MAX 200005

using namespace std;

const ld EPSILON = 0.0000001;

ll n, c, d;
vector<ll> coins;

bool able(ll k){
  if(k == 0) return coins[0]*d >= c;
  ll sum = 0, multiplier = 0;
  multiplier = d/(k + 1);

  FOR(i, 0, min(k + 1, n)) sum += coins[i];
  if(multiplier == 0) return sum >= c;
  sum *= multiplier;

  FOR(i, 0, min(d%(k + 1), n)) sum += coins[i];
  return sum >= c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> n >> c >> d;
    coins.assign(n, {});
    FOR(i, 0, n) cin >> coins[i];
    sort(coins.rbegin(), coins.rend());

    int l = 0, r = d, m;
    while(l <= r) {
      m = (l + r)/2;
      if(able(m)) l = m + 1;
      else r = m - 1;
    }

    if(l > d) cout << "Infinity\n";
    else if(r < 0) cout << "Impossible\n";
    else if(able(l)) cout << l << "\n";
    else cout << r << "\n";
  }
 
  return 0;
}