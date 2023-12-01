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

  int t; cin >> t;
  int n, l, r, m, x;

  while(t--){
    cin >> n >> x;
    vector<int> p(x + 1);
    FOR(i, 0, n){
      int a;
      cin >> a;
      if(a > x) continue;
      p[a] = 1;
    }

    l = 0; r = 2*x + 2; 
    while(l <= r){
      m = (l + r)/2;

      int ax = m;
      bool able = true;
      FOR(i, 0, x){
        if(ax <= 0){
          able = false;
          break;
        }

        ax--;
        if(p[i + 1]) ax = m;
      }

      FORI(i, x, 1){
        if(ax <= 0){
          able = false;
          break;
        }

        ax--;
        if(p[i - 1]) ax = m;
      }

      if(able) r = m - 1;
      else l = m + 1;
    }

    cout << l << "\n";
  }
  
  return 0;
}