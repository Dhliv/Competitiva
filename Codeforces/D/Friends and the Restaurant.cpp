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

  int t; cin >> t;
  int n, ans, x;

  FOR(ab, 0, t){
    cin >> n;
    ans = 0;

    vector<int> p(n), pos, neg;
    FOR(i, 0, n) cin >> p[i];

    FOR(i, 0, n){
      cin >> x;
      int val = x - p[i];
      if(val >= 0) pos.PB(val);
      else neg.PB(-val);
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    int i = 0, j = 0;

    while(i < pos.size() and j < neg.size()) {
      if(pos[i] >= neg[j]){
        ans++;
        i++;
      }

      j++;
    }

    ans += (pos.size() - i)/2;

    cout << ans << "\n";
  }

  return 0;
}