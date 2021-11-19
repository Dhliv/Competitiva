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
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, ans, res, x, n;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(n);
    FOR(i, 0, n) cin >> p[i];

    sort(p.begin(), p.end());

    ans = p[0];
    res = 0;

    FOR(i, 0, n){
      x = p[i] - res;
      ans = max(ans, x);
      res += x;
    }

    cout << ans << "\n";
  }
  
  return 0;
}