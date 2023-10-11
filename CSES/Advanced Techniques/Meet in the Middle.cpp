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
 
const ld EPSILON = 0.000000001;

struct dt{
  ll ele, tms;

  dt(){}
  dt(ll ele, ll tms) : ele(ele), tms(tms) {}
};

void mitm(int pos, int n, vector<int> &p, deque<ll> &app){
  int max = 1 << n;
  ll ele;
  FOR(i, 0, max){
    ele = 0;
    FOR(j, 0, n){
      if(i & (1 << j)) ele += p[j + pos];
    }

    app.PB(ele);
  }
}

int bs(ll x, deque<dt> &p){
  int l = 0, r = p.size(), m;

  while(l <= r){
    m = (l + r)/2;

    if(p[m].ele >= x) r = m - 1;
    else l = m + 1;
  }

  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  ll x; cin >> x;

  if(n == 1){
    ll d;
    cin >> d;
    if(d == x) cout << "1\n";
    else cout << "0\n";
    return 0;
  }

  vector<int> p(n); FOR(i, 0, n) cin >> p[i];

  deque<ll> app1, app2;
  int fh = n/2;
  mitm(0, fh, p, app1);
  mitm(fh, n - fh, p, app2);
  app1.PB(LLONG_MAX);
  app2.PB(LLONG_MAX);
  sort(app1.begin(), app1.end());
  sort(app2.begin(), app2.end());

  deque<dt> a1, a2;
  ll bef = app1[0];
  ll cnt = 1;
  FOR(i, 1, app1.size()){
    if(app1[i] == bef){
      cnt++;
      continue;
    }

    a1.PB(dt(bef, cnt));
    bef = app1[i];
    cnt = 1;
  }

  bef = app2[0];
  cnt = 1;
  FOR(i, 1, app2.size()){
    if(app2[i] == bef){
      cnt++;
      continue;
    }

    a2.PB(dt(bef, cnt));
    bef = app2[i];
    cnt = 1;
  }

  ll ans = 0;
  int pos;
  FOR(i, 0, a1.size()){
    if(a1[i].ele > x) break;
    pos = bs(x - a1[i].ele, a2);
    if(pos == a2.size() or a2[pos].ele != x - a1[i].ele) continue;

    ans += a1[i].tms*a2[pos].tms;
  }
  cout << ans << "\n";

  return 0;
}