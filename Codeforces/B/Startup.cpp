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
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  FOR(ab, 0, t) {
    int n, k; cin >> n >> k;
    vector<int> p(k + 1);
    FOR(i, 0, k) {
      int b, c; cin >> b >> c;
      p[b] += c;
    }

    vector<int> ans;
    FOR(i, 1, k + 1) {
      if(p[i] == 0) continue;
      ans.PB(p[i]);
    }

    int sol = 0;
    sort(ans.rbegin(), ans.rend());
    FOR(i, 0, min(n, int(ans.size()))) sol += ans[i];

    cout << sol << '\n';
  }
  
  return 0;
}