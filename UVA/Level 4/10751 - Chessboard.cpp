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
  cout.precision(3);

  int t; cin >> t;
  int n;
  ld x, y, cuatro = 4.0, ans;

  while(t--){
    cin >> n;
    if(n == 1) cout << "0.000\n";
    else{
      x = cuatro*(n - 1);
      y = (n - 2)*(n - 2);

      ans = x + y*sqrt(2);
      cout << fixed << ans << "\n";
    }
  }

  return 0;
}