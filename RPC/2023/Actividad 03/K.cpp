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
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int man(pair<int, int> a, pair<int, int> b){
  return abs(a.f - b.f) + abs(a.s - b.s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  int x, y, xa, ya;
  vector<pair<int, int> > p(n + 1); FOR(i, 0, n) cin >> p[i].f >> p[i].s;
  p[n] = MP(INF, INF);
  sort(p.begin(), p.end());

  deque<deque<int> > nds;
  int bef, idx;
  idx = 0;
  bef = p[0].f;

  FOR(i, 1, n + 1){
    if(bef == p[i].f) continue;
    deque<int> ax(1, idx);
    if(idx != i - 1) ax.PB(i - 1);
    bef = p[i].f;
    idx = i;
    nds.PB(ax);
  }

  vector<ll> manha(n);
  FOR(i, 0, nds.size()){
    if(nds[i].size() == 1) continue;
    ll m = man(p[nds[i][0]], p[nds[i][1]]);
    FOR(j, 0, nds[i].size()) manha[nds[i][j]] = m;
  }

  vector<ll> seen(n, LLONG_MAX);
  FOR(i, 0, nds[0].size()) seen[nds[0][i]] = manha[nds[0][i]];
  FOR(i, 1, nds.size()){
    if(nds[i].size() == 2){
      x = nds[i][0];
      y = nds[i][1];

      xa = nds[i - 1][0];
      if(nds[i - 1].size() == 2){
        ya = nds[i - 1][1];
        seen[x] = manha[x] + min(seen[xa] + man(p[y], p[xa]), seen[ya] + man(p[y], p[ya]));
        seen[y] = manha[y] + min(seen[xa] + man(p[x], p[xa]), seen[ya] + man(p[x], p[ya]));
      }else{
        seen[x] = manha[x] + seen[xa] + man(p[xa], p[y]);
        seen[y] = manha[y] + seen[xa] + man(p[xa], p[x]);
      }
    }else{
      FOR(j, 0, nds[i - 1].size()) seen[nds[i][0]] = min(seen[nds[i][0]], seen[nds[i - 1][j]] + man(p[nds[i][0]], p[nds[i - 1][j]]));
    }
  }

  ll ans = LLONG_MAX;
  FOR(i, 0, nds[nds.size() - 1].size()) ans = min(ans, seen[nds[nds.size() - 1][i]]);
  cout << ans << "\n";

  return 0;
}