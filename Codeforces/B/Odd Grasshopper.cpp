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

  int t;
  ll n, ans, x0, ax, x;
  cin >> t;

  FOR(ab, 0, t){
    cin >> x0 >> n;
    ans = x0;
    if(n){
      ans = (x0 & 1 ? 1 : -1) + x0;
      ans += (x0 & 1 ? 1 : -1)*(4*((n - 1)/4));

      x = 4*((n - 1)/4) + 2;
      ax = 0;

      FOR(i, x, n + 1){
        if(i - x > 1) ax += i;
        else ax -= i;
      }

      ax *= (x0 & 1 ? 1 : -1);

      ans += ax;
    }

    cout << ans << "\n";
  }
  
  return 0;
}