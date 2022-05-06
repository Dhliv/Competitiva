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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t, n, ans, x, b, l, r; cin >> t;
 
  FOR(ab, 0, t) {
    cin >> n;
    b = 0;
    l = INF;
    r = MINF;
 
    FOR(i, 0, n){
      cin >> x;
      if(b == x){
        l = min(l, (int)i);
        r = max(r, (int)i);
      }
      b = x;
    }
 
    if(l == INF or l == r) ans = 0;
    else if(l + 1 == r) ans = 1;
    else ans = r - l - 1;
 
    cout << ans << "\n";
  }
 
  return 0;
}