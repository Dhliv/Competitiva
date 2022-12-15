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
#define PI 3.14159265358979323846

using namespace std;

const double EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, ans, div;
  int id = 1;

  while(t--){
    cout << "Case " << id++ << ": ";
    cin >> n;
    if(n == 1){
      cout << "0\n";
      continue;
    }

    ans = n*(n - 1)/2;
    div = 2;
    if(ans%2 == 0) cout << ans/2 << "\n";
    else cout << ans << "/" << div << "\n";
  }

  return 0;
}