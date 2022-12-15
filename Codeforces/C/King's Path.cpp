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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int xo, yo, xf, yf, n, x, y, r;
  ll MAX = 1000000000;
  cin >> xo  >> yo >> xf >> yf;

  cin >> n;
  set<pair<int, int > > m;

  FOR(i, 0, n){
    cin >> r >> x >> y;
    FOR(j, x, y + 1) m.insert(MP(r, j));
  }

  deque<pair<int, int> > q;
  pair<int, int> ax, par;
  map<pair<int, int>, int> seen;
  q.PB(MP(xo, yo));
  seen.insert(MP(MP(xo, yo), 0));

  int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

  while(!q.empty()){
    ax = q.F(); q.P_F();
    auto bef = seen.find(ax);

    FOR(i, 0, 8){
      x = ax.f + dx[i];
      y = ax.s + dy[i];
      par = MP(x, y);

      if(m.find(par) == m.end()) continue;
      auto it = seen.find(par);
      if(it != seen.end()) continue;
      //cout << x << " " << y << "\n";

      seen.insert(MP(par, bef->s + 1));
      q.PB(par);
    }
  }

  par = MP(xf, yf);
  auto it = seen.find(par);
  if(it == seen.end()) cout << "-1\n";
  else cout << it->s << "\n";

  return 0;
}