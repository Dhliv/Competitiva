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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, k, ans, x; cin >> t;

  FOR(ab, 0, t){
    cin >> n >> k;
    string s; cin >> s;

    if(s[n - 1] == '0'){
      FORI(i, n - 2, 0){
        if(s[i] == '1'){
          if((n - i - 1) <= k){
            swap(s[i], s[n - 1]);
            k -= (n - i - 1);
          }
          break;
        }
      }
    }

    if(s[0] == '0'){
      FOR(i, 1, n - 1){
        if(s[i] == '1'){
          if(i <= k) swap(s[0], s[i]);
          break;
        }
      }
    }

    ans = 0;
    FOR(i, 0, n - 1){
      x = (s[i] - '0')*10 + (s[i + 1] - '0');
      ans += x;
    }

    cout << ans << "\n";
  }

  return 0;
}