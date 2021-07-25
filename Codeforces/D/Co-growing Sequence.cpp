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

  int t, n, must;
  bool tg, tgx;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> x(n), y(n);
    must = 0;

    FOR(i, 0, n) cin >> x[i];

    FOR(i, 0, n){
      FOR(j, 0, 31){
        must |= (x[i] & 1 << j);
        tg = ((must & 1 << j) != 0);
        tgx = ((x[i] & 1 << j) != 0);
        y[i] |= ((tg ^ tgx) << j);
      }
    }

    FOR(i, 0, n) cout << y[i] << " ";
    cout << "\n";
  }

  return 0;
}