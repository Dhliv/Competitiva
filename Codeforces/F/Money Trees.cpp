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
  ll n, x;

  while(t--){
    cin >> n >> x;
    vector<int> f(n + 1), h(n + 1);
    FOR(i, 0, n) cin >> f[i];
    FOR(i, 0, n) cin >> h[i];
    h[n] = f[n] = INF;

    int l = 0;
    ll sum = 0;
    ll ans = 0;

    FOR(i, 0, n + 1){
      if(f[i] <= x){
        l = i;
        ans = 1;
        sum = f[i];
        break;
      }

      if(i == n) l = n + 1;
    }

    FOR(i, l + 1, n + 1){
      if(h[i - 1]%h[i] != 0){
        //cout << "h // h+1 IN " << i << " & " << l << "\n";
        ans = max(ans, i - l);
        sum = f[i];
        l = i;
        continue;
      }

      while(sum + f[i] > x){
        ans = max(ans, i - l);
        sum -= f[l++];
      }

      sum += f[i];
    }

    cout << ans << "\n";
  }

  return 0;
}