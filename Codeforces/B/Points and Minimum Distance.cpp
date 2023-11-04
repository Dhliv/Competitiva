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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;
    vector<int> p(2*n); FOR(i, 0, 2*n) cin >> p[i];
    sort(p.begin(), p.end());

    vector<pair<int, int> > pts(n);
    FOR(i, 0, n) pts[i] = MP(p[i], p[2*n - 1 - i]);

    ll ans = 0;
    pair<int, int> pt = pts[0];
    FOR(i, 1, n){
      ans += abs(pt.f - pts[i].f) + abs(pt.s - pts[i].s);
      pt = pts[i];
    }

    cout << ans << "\n";
    FOR(i, 0, n) cout << pts[i].f << " " << pts[i].s << "\n";
  }

  return 0;
}