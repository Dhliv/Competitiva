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

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll a, b, x, y;

  while(t--){
    cin >> a >> b;
    x = max((ll) 0, (2*b - a)/3);
    y = max((ll) 0, b - 2*x);

    a -= (x + 2*y);
    b -= (2*x + y);

    if(a == 0 and b == 0) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}