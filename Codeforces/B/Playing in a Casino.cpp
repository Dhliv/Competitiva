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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, m, x;
  ll ans;

  while(t--){
    cin >> n >> m;
    vector<vector<int> > p(m, vector<int> (n));
    vector<ll> sum(m);

    FOR(i, 0, n){
      FOR(j, 0, m){
        cin >> p[j][i];
        sum[j] += p[j][i];
      }
    }

    FOR(i, 0, m) sort(p[i].begin(), p[i].end());

    ans = 0;
    FOR(i, 0, m){
      FOR(j, 0, n - 1){
        x = p[i][j];
        sum[i] -= x;

        ans += (sum[i] - x*(n - j - 1));
      }
    }

    cout << ans << "\n";
  }

  return 0;
}