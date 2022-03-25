#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

  int t, n, ans, sum, act, neoSum; cin >> t;
  bool able;

  FOR(ab, 0, t){
    cin >> n;
    ans = 0;
    deque<int> p(n);
    sum = 0;
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 0, n) sum += p[i];

    FORI(i, n, 1){
      able = true;
      act = 0;
      if(sum % i != 0) continue;

      neoSum = sum/i;
      FOR(j, 0, n){
        act += p[j];
        if(act > neoSum){
          able = false;
          break;
        }else if(act == neoSum) act = 0;
      }

      if(able and act == 0){
        ans = n - (int)i;
        break;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
