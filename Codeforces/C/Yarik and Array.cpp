#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n; cin >> t;

  while(t--){
    cin >> n;
    int sum = 0, ans = MINF;
    int l = -1, x, mod;

    FOR(i, 0, n){
      cin >> x;
      mod = (x%2 + 2)%2;
      if(mod == l){
        ans = max(ans, sum);
        sum = x;
      }else{
        sum += x;
        l = mod;
      }

      ans = max(ans, sum);
      if(sum < 0){
        sum = 0;
        l = -1;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}