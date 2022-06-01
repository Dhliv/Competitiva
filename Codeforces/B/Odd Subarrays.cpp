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

  int t, n, ans; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(n); FOR(i, 0, n) cin >> p[i];
    priority_queue<int> pq;

    ans = 0;
    FORI(i, n - 1, 0){
      pq.push(-p[i]);

      if(-pq.top() < p[i]){
        ans++;
        while(!pq.empty()) pq.pop();
      }
    }

    cout << ans << "\n";
  }

  return 0;
}