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

  int t, n, k, x, y, c;
  int dx[2] = {1, -1};
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> k;
    n++;
    vector<int> s(n, INF), v(n), p(k);
    priority_queue<pair<int, int> > q;

    FOR(i, 0, k) cin >> p[i];
    FOR(i, 0, k){
      cin >> c;
      s[p[i]] = c;
      q.push(MP(-c, p[i]));
    }

    while(!q.empty()){
      x = q.top().s;
      q.pop();

      if(v[x]) continue;
      v[x] = 1;

      FOR(i, 0, 2){
        y = x + dx[i];
        if(y < 1 or y >= n) continue;
        if(v[y]) continue;

        if(s[y] > s[x] + 1){
          s[y] = s[x] + 1;
          q.push(MP(-s[y], y));
        }
      }
    }

    FOR(i, 1, n) cout << s[i] << " ";
    cout << "\n";
  }

  return 0;
}