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
  
  int t, n, l, r, p1, p2;
  ll ans;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> l >> r;
    vector<int> p(n);
    FOR(i, 0, n) cin >> p[i];
    
    sort(p.begin(), p.end());
    
    ans = 0;
    FOR(i, 0, n - 1){
      if(p[i] >= r) break;
      if(p[i] < l){
        p1 = lower_bound(p.begin() + i + 1, p.end(), l - p[i]) - p.begin();
        p2 = upper_bound(p.begin() + i + 1, p.end(), r - p[i]) - p.begin();
        ans += (p2 - p1);
        //cout << p1 << " " << p2 << ": " << l - p[i] << " " << r - p[i] << "\n";
      }else{
        p2 = upper_bound(p.begin() + i + 1, p.end(), r - p[i]) - p.begin();
        ans += p2 - (i + 1);
        //cout << i << " " << p2 << "\n";
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}