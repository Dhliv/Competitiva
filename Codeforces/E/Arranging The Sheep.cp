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
  
  int t, n, l, r, m, acum;
  ll ans, ax;
  string a;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> a;
    deque<int> p;
    FOR(i, 0, n) if(a[i] == '*') p.PB(i);
    
    n = p.size();
    
    m = n/2;
    ans = 0;
    
    acum = 1;
    FORI(i, m - 1, 0) ans += (p[m] - (p[i] + acum++));
    
    acum = 1;
    FOR(i, m + 1, n) ans += (p[i] - (p[m] + acum++));
      
    if(n%2) cout << ans << "\n";
    else{
      m = n/2 - 1;
      ax = 0;
      
      acum = 1;
      FORI(i, m - 1, 0) ax += (p[m] - (p[i] + acum++));
      
      acum = 1;
      FOR(i, m + 1, n) ax += (p[i] - (p[m] + acum++));
      cout << min(ans, ax) << "\n";
    }
  }
  
  return 0;
}