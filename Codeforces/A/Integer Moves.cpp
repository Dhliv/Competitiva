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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t, n, a, b, c, x, y; cin >> t;
 
  vector<pair<int, int> > poss;
 
  FOR(i, 1, 50) {
    FOR(j, 1, 51) {
      a = i*i;
      b = j*j;
      c = sqrt(a + b);
 
      if(c*c == a + b) poss.PB(MP(i, j));
    }
  }
 
  int dx[4] = {-1, 1, 1, -1};
  int dy[4] = {-1, 1, -1, 1};
  vector<vector<int> > ans(51, vector<int> (51, -1));
  ans[0][0] = 0;
  deque<pair<int, int> > p;
  pair<int, int> aux;
  p.PB(MP(0, 0));
 
  while(!p.empty()) {
    auto x = p.F(); p.P_F();
 
    FOR(i, 0, 51){
      if(ans[i][x.s] == -1) {
        ans[i][x.s] = ans[x.f][x.s] + 1;
        p.PB(MP(i, x.s));
      }
 
      if(ans[x.f][i] == -1) {
        ans[x.f][i] = ans[x.f][x.s] + 1;
        p.PB(MP(x.f, i));
      }
    }
 
    FOR(i, 0, poss.size()) {
      int a, b;
 
      FOR(j, 0, 4) {
        a = x.f + dx[j]*poss[i].f;
        b = x.s + dy[j]*poss[i].s;
 
        if(a < 0 or a > 50 or b < 0 or b > 50) continue;
        if(ans[a][b] != -1) continue;
        ans[a][b] = ans[x.f][x.s] + 1;
        p.PB(MP(a, b));
      }
    }
  }
 
  FOR(ab, 0, t){
    cin >> x >> y;
 
    cout << ans[x][y] << "\n";
  }
 
  return 0;
}