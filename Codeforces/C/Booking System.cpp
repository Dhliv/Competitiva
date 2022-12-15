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

const ld EPSILON = 0.0000001;

struct dat{
  int c, p, index;
};

struct mesa{
  int n;
  deque<int> p;

  mesa(int n, int x): n(n){
    p.PB(x);
  }
};

bool comp(const dat &a, const dat &b){
  if(a.p == b.p) return a.c < b.c;
  return a.p > b.p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y; cin >> n;
  int r;

  vector<dat> p(n);

  FOR(i, 0, n){
    cin >> p[i].c >> p[i].p;
    p[i].index = i + 1;
  }
  sort(p.begin(), p.end(), comp);

  map<int, mesa> m;
  cin >> r;
  FOR(i, 0, r){
    cin >> x;
    auto it = m.find(x);
    if(it == m.end()){
      mesa a(1, i + 1);
      m.insert(MP(x, a));
    }
    else{
      it->s.p.PB(i + 1);
      it->s.n++;
    }
  }

  ll ans = 0;
  deque<pair<int, int> > req;
  FOR(i, 0, n){
    auto ele = m.lower_bound(p[i].c);
    if(ele == m.end()) continue;
    ans += p[i].p;
    req.PB(MP(p[i].index, ele->s.p.B()));
    ele->s.n--;
    ele->s.p.P_B();
    if(ele->s.n == 0) m.erase(ele);
  }

  cout << req.size() << " " << ans << "\n";
  FOR(i, 0, req.size()){
    cout << req[i].f << " " << req[i].s << "\n";
  }

  return 0;
}