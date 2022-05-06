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

  int t, n, ans; cin >> t;
  bool able;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(n); FOR(i, 0, n) cin >> p[i];
    sort(p.begin(), p.end());

    if(n == 1 and p[0] > 1) cout << "NO\n";
    else if(n == 1) cout << "YES\n";
    else{
      able = true;
      if(p[n - 1] - p[n - 2] > 1) able = false;

      if(able) cout << "yes\n";
      else cout << "no\n";
    }
  }

  return 0;
}
