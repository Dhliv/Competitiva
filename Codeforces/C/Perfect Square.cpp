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
 
const ld EPSILON = 0.000000001;

int n;

vector<pair<int, int> > allRotations(int i, int j){
  int ni, nj;
  vector<pair<int, int> > ans(4);

  ans[0] = MP(i, j);
  FOR(i, 1, 4){
    ni = ans[i - 1].s;
    nj = n - 1 - ans[i - 1].f;
    ans[i] = MP(ni, nj);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int ni, nj;

  while(t--){
    cin >> n;
    vector<string> p(n);
    vector<vector<int> > sn(n, vector<int> (n));
    ll ans = 0;
    FOR(i, 0, n) cin >> p[i];

    FOR(i, 0, n){
      FOR(j, 0,n){
        if(sn[i][j]) continue;

        vector<pair<int, int> > a = allRotations(i, j);
        int maxi = 0;
        FOR(k, 0, 4) maxi = max(maxi, (int)p[a[k].f][a[k].s]);
        FOR(k, 0, 4){
          ans += maxi - p[a[k].f][a[k].s];
          sn[a[k].f][a[k].s] = 1;
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}