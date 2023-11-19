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

const ld EPSILON = 0.0000000001;

int n;

ll maxRes(int k, vector<ll> &p){
  ll maxi = 0, mini = LLONG_MAX;
  ll cur = 0;
  int cnt = 0;
  FOR(j, 0, n){
    cur += p[j];
    cnt++;

    if(cnt == k){
      maxi = max(maxi, cur);
      mini = min(mini, cur);
      cnt = 0;
      cur = 0;
    }
  }

  return maxi - mini;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> n;
    vector<ll> p(n); FOR(i, 0, n) cin >> p[i];

    int upper = sqrt(n);
    if(upper*upper != n) upper++;

    ll ans = maxRes(1, p);
    FOR(i, 2, upper){
      if(n%i) continue;
      ans = max(ans, maxRes(i, p));
      ans = max(ans, maxRes(n/i, p));
    }

    if(upper*upper == n) ans = max(ans, maxRes(upper, p));

    cout << ans << "\n";
  }

  return 0;
}