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

ll a, b, c, d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll x, y, ab;
  bool ans;
  while(t--){
    ans = false;
    cin >> a >> b >> c >> d;

    ab = a*b;
    FOR(i, b + 1, d + 1){
      x = ab/__gcd(ab, i);

      if(x > c) continue;
      if(x <= a){
        x *= ((a/x) + 1);
      }
      if(x > a and x <= c){
        ans = true;
        cout << x << " " << i << "\n";
        break;
      }
    }

    if(!ans) cout << "-1 -1\n";
  }


  return 0;
}