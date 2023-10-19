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

const ld EPSILON = 0.0000000001;

struct edge{
  int x, y;
  ll w;

  edge(){}
  edge(int x, int y, ll w) : x(x), y(y), w(w) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m; cin >> n >> m;
  int x, y;
  ll w;
  vector<vector<edge> > g(n + 1);
  FOR(i, 0, m){
    cin >> x >> y >> w;
    g[x].PB(edge(x, y, w));
  }

  vector<vector<ll> > sn(n + 1, vector<ll> (2, LLONG_MAX));
  vector<vector<bool> > v(n + 1, vector<bool> (2));
  priority_queue<pair<ll, pair<int, int> > > pq; // cost, node and coupons used.
  sn[1][0] = 0;
  pq.push(MP(0, MP(1, 0)));

  while(!pq.empty()){
    x = pq.top().s.f; // node.
    y = pq.top().s.s; // coupons used.
    pq.pop();

    if(v[x][y]) continue;
    v[x][y] = 1;

    for(const edge &e: g[x]){
      if(y == 1 and v[e.y][y]) continue;
      w = sn[x][y];
      if(w + e.w < sn[e.y][y]){
        sn[e.y][y] = w + e.w;
        pq.push(MP(-sn[e.y][y], MP(e.y, y)));
      }

      if(y == 0 and w + (e.w)/2 < sn[e.y][y + 1]){
        sn[e.y][y + 1] = w + e.w/2;
        pq.push(MP(-sn[e.y][y + 1], MP(e.y, y + 1)));
      }
    }
  }

  cout << min(sn[n][0], sn[n][1]) << "\n";

  return 0;
}