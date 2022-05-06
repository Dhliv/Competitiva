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
 
  int t, n; cin >> t;
  ll ans, maxi, last_day, day, eles, sum, x;
 
  FOR(ab, 0, t) {
    cin >> n >> maxi;
    vector<ll> p(n);
 
    last_day = -1;
    eles = n;
    sum = ans = 0;
 
    FOR(i, 0, n){
      cin >> p[i];
      sum += p[i];
    }
 
    sort(p.begin(), p.end());
 
    while(!p.empty()){
      day = (maxi - sum)/eles;
 
      if(day <= last_day or maxi < sum){
        sum -= p.B();
        eles--;
        p.P_B();
      }else{
        ans += (day - last_day)*eles;
        last_day = day;
      }
    }
 
    cout << ans << "\n";
  }
 
  return 0;
}