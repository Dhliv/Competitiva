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

  int n, k, m, t, l, r;
  bool able;
  cin >> t;

  FOR(ab, 0, t){
    cin >> k >> n >> m;
    l = r = 0;
    able = 1;
    deque<int> ans;

    vector<int> a(n), b(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];

    while(true){
      if(l < n and a[l] <= k){
        if(a[l] == 0) k++;
        ans.PB(a[l]);
        l++;
      }else if(r < m and b[r] <= k){
        if(b[r] == 0) k++;
        ans.PB(b[r]);
        r++;
      }else if(l == n and r == m) break;
      else{
        able = false;
        break;
      }
    }

    if(able){
      FOR(i, 0, ans.size()) cout << ans[i] << " ";
      cout << "\n";
    }else cout << "-1\n";
  }

  return 0;
}