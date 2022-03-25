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

  int n; cin >> n;
  int ans = 0, sum, ele;
  vector<int> has(1001), p(n);

  FOR(i, 0, n) cin >> p[i];

  FOR(i, 0, n){
    FOR(j, 0, n) has[p[j]] = 0;

    sum = 0;
    ele = 0;
    FOR(j, i, n){
      ele++;
      has[p[j]] = 1;
      sum += p[j];

      if(sum % ele == 0 and has[sum/ele]) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}
