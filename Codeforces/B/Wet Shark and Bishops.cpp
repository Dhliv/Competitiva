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
#define PI 3.14159265358979323846

using namespace std;

const double EPSILON = 0.0000001;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
  if(a.s == b.s) return a.f < b.f;
  return a.s < b.s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<vector<int> > has(1001, vector<int> (1001)), dp1(1001, vector<int> (1001)), dp2(1001, vector<int> (1001));
  vector<pair<int, int> > pts(n);
  FOR(i, 0, n){
    cin >> pts[i].f >> pts[i].s;
    has[pts[i].f][pts[i].s] = 1;
  }

  sort(pts.begin(), pts.end(), comp);
  int x, y;
  ll ans = 0;

  FOR(i, 0, n){
    x = pts[i].f; y = pts[i].s;
    ans += dp1[x][y] + dp2[x][y];
    //cout << x << " " << y << ": " << dp1[x][y] << " and " << dp2[x][y] << "\n";

    FOR(j, 1, 1001){
      x++; y++;
      if(x > 1000 or y > 1000) break;
      if(has[x][y]){
        dp1[x][y] += dp1[pts[i].f][pts[i].s] + 1;
        break;
      }
    }

    x = pts[i].f; y = pts[i].s;
    FOR(j, 1, 1001){
      x--; y++;
      if(x < 1 or y > 1000) break;
      if(has[x][y]){
        dp2[x][y] += dp2[pts[i].f][pts[i].s] + 1;
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}