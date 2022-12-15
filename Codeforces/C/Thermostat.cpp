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
  ll x, l, r, a, b, ax, bx;

  while(t--){
    cin >> l >> r >> x;
    cin >> a >> b;

    if(a == b) cout << "0\n";
    else if(l <= b and b <= r){
      if(abs(b - a) >= x) cout << "1\n";
      else if((max(a, b) + x <= r and max(a, b) + x >= l) or (min(a, b) - x <= r and min(a, b) - x >= l)) cout << "2\n";
      else{
        ax = max(a, b) - x;
        bx = min(a, b) + x;
        if(l <= ax and ax <= r and l <= bx and bx <= r) cout << "3\n";
        else cout << "-1\n";
      }
    }else cout << "-1\n";
  }

  return 0;
}