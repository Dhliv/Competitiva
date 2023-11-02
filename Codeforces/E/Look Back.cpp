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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, pw;
  while(t--){
    cin >> n;
    vector<ll> p(n); FOR(i, 0, n) cin >> p[i];
    pw = 0;
    ll ans = 0;
    FOR(i, 1, n) {
      ll x = p[i];
      if(p[i] >= p[i - 1]){
        x = p[i - 1];
        while(pw and p[i] >= 2*x){
          pw--;
          x <<= 1;
        }
      }else{
        while(2*x < p[i - 1]){
          x <<= 1;
          pw++;
        }

        if(x < p[i - 1]) pw++;
      }

      ans += pw;
      //cout << "-> " << pw << "\n";
    }

    cout << ans << "\n";
  }

  return 0;
}