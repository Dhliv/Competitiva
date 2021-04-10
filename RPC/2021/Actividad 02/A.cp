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
  cout.precision(9);
  int n, m, p, pos;
  ll x, y, mini, a;
  ld ans;
  
  cin >> n >> m >> p;
  vector<pair<int, int> > ju(n), al(m), pl(p);
  
  FOR(i, 0, n){
    cin >> x >> y;
    ju[i] = MP(x, y);
  }
  
  FOR(i, 0, m){
    cin >> x >> y;
    al[i] = MP(x, y);
  }
  
  FOR(i, 0, p){
    cin >> x >> y;
    pl[i] = MP(x, y);
  }
  
  deque<pair<ll, pair<int, int> > > s1, s2;
  
  FOR(i, 0, n){
    FOR(j, 0, m){
      x = ju[i].f - al[j].f;
      y = ju[i].s - al[j].s;
      s1.PB(MP(x*x + y*y, MP(i, j)));
    }
  }
  
  FOR(i, 0, n){
    FOR(j, 0, p){
      x = ju[i].f - pl[j].f;
      y = ju[i].s - pl[j].s;
      s2.PB(MP(x*x + y*y, MP(i, j)));
    }
  }
  
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  
  ans = 0.0;
  vector<int> js1(n), js2(n), als(m), pls(p);
  FOR(i, 0, s1.size()){
    x = s1[i].s.f;
    y = s1[i].s.s;
    if(js1[x]) continue;
    if(als[y]) continue;
    ans += sqrt(s1[i].f);
    js1[x] = 1;
    als[y] = 1;
  }
  
  FOR(i, 0, s2.size()){
    x = s2[i].s.f;
    y = s2[i].s.s;
    if(js2[x]) continue;
    if(pls[y]) continue;
    ans += sqrt(s2[i].f);
    js2[x] = 1;
    pls[y] = 1;
  }
  
  cout << fixed << ans << "\n";
  
  return 0;
}