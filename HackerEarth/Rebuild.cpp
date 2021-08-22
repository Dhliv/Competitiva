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

bool comp(pair<ll, pair<int, int> > &a, pair<ll, pair<int, int> > &b){
  if(a.f < b.f) return 1;
  else if(a.f == b.f){
    int x, y;
    x = min(a.s.f, a.s.s);
    y = min(b.s.f, b.s.s);
    if(x > y) return 1;
    else if(x == y){
      x = max(a.s.f, a.s.s);
      y = max(b.s.f, b.s.s);
      if(x > y) return 1;
    }
  }
  return 0;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[a] < s[b]) swap(a, b);
  p[b] = a;
  s[a] += s[b];
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, x, y, xf, yf;
  ll ans, c;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> m;
    vector<int> p(n + 1), s(n + 1, 1), in(n + 1);
    FOR(i, 1, n + 1) p[i] = i;

    deque<pair<ll, pair<int, int> > > q(m);
    FOR(i, 0, m){
      cin >> x >> y >> c;
      q[i] = MP(c, MP(x, y));
    }

    sort(q.begin(), q.end(), comp);

    ans = 0;
    FOR(i, 0, m){
      x = q[i].s.f;
      y = q[i].s.s;
      c = q[i].f;
      xf = find(x, p);
      yf = find(y, p);

      if(xf != yf){
        ans += c;
        in[x]++;
        in[y]++;
        com(xf, yf, p, s);
      }
    }

    cout << ans << "\n";
    cout << in[1];
    FOR(i, 2, n + 1) cout << " " << in[i];
    cout << "\n";
  }

  return 0;
}