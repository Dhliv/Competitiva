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

ll n, k;
ll p[20];

ll f(int i, int left, __int128 pr){
  if(pr > n) return 0;
  if(!left) return (ll) n/pr;
  ll ans = 0;
  FOR(j, i + 1, k - left + 1){
    ans += f(j, left - 1, pr*p[j]);
  }

  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  FOR(i, 0, k) cin >> p[i];

  ll ans = 0;
  FOR(i, 1, k + 1){
    if(i & 1) ans += f(-1, i, 1);
    else ans -= f(-1, i, 1);
  }

  cout << ans << "\n";

  return 0;
}
