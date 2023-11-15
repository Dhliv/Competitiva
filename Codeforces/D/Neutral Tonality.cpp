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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m; cin >> t;

  FOR(ab, 1, t + 1){
    cin >> n >> m;
    vector<int> a(n); FOR(i, 0, n) cin >> a[i];
    deque<int> b(m); FOR(i, 0, m) cin >> b[i];
    sort(b.rbegin(), b.rend());

    int l = 0, r = 0;
    deque<int> ans;
    while(l < n and r < m){
      if(b[r] >= a[l]){
        ans.PB(b[r++]);
        continue;
      }

      ans.PB(a[l++]);
    }

    while(l < n) ans.PB(a[l++]);
    while(r < m) ans.PB(b[r++]);

    FOR(i, 0, ans.size()) cout << ans[i] << " ";
    cout << "\n";
  }

  return 0;
}