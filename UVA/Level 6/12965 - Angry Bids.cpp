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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, ans, mini, ax;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> m;
    vector<int> a(n), b(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(m == 0 and n == 0) cout << "0 0\n";
    else if(n == 0) cout << "0 0\n";
    else if(m == 0) cout << a[n - 1] << " 0\n";
    else{
      mini = INF;
      ans = INF;

      FOR(i, 0, m){
        ax = i;
        ax += n - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
        if(ax < mini){
          mini = ax;
          ans = b[i];
        }else if(ax == mini) ans = min(ans, b[i]);
      }

      FOR(i, 0, n){
        ax = n - 1 - i;
        ax += (upper_bound(b.begin(), b.end(), a[i]) - b.begin());
        if(ax < mini){
          mini = ax;
          ans = a[i];
        }else if(ax == mini) ans = min(ans, a[i]);
      }

      if(n <= mini){
        mini = n;
        ans = 0;
      }

      cout << ans << " " << mini << "\n";
    }
  }

  return 0;
}