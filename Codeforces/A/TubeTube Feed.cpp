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

  int q, t, s, n, maxi, ans; cin >> q;

  while(q--){
    cin >> n >> t;
    maxi = ans = -1;
    vector<int> a(n), b(n);

    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];

    FOR(i, 0, n){
      if(a[i] + i > t) continue;
      if(b[i] < maxi) continue;
      maxi = b[i];
      ans = i + 1;
    }

    cout << ans << "\n";
  }
 
  return 0;
}