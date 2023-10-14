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
  ld l, t;

  edge(){}
  edge(int x, int y, ld l, ld t) : x(x), y(y), l(l), t(t) {}
};

int n;
ld t;
vector<vector<int> > g;
vector<edge> edges;

void addEdge(int x, int y, ld l, ld t){
  g[x].PB(edges.size());
  edges.PB(edge(x, y, l, t));
  g[y].PB(edges.size());
  edges.PB(edge(y, x, l, t));
}

ld dijkstra(ld speed){
  const ld MAX = LLONG_MAX;
  vector<int> v(g.size());
  vector<ld> s(g.size(), MAX);
  priority_queue<pair<ld, int> > pq;
  s[0] = 0.0;
  pq.push(MP(0, 0));
  int x, y;
  ld w;

  while(!pq.empty()){
    x = pq.top().s;
    pq.pop();

    if(fabs(t - s[x]) >= EPSILON and s[x] > t) return s[n - 1];
    if(v[x]) continue;
    v[x] = 1;

    for(const int &e_id: g[x]){
      edge &e = edges[e_id];
      if(v[e.y]) continue;
      w = s[x] + e.l/(e.t + speed);
      if(fabs(w - s[e.y]) < EPSILON or w >= s[e.y]) continue;
      s[e.y] = w;
      pq.push(MP(-w, e.y));
    }
  }

  return s[n - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(8);

  int m; cin >> n >> m >> t;

  int x, y;
  ld l, tt;

  g.assign(n, {});
  FOR(i, 0, m){
    cin >> x >> y >> l >> tt;
    x--;
    y--;
    addEdge(x, y, l, tt);
  }

  ld lo = 0.0, r = 1000000000.0, mid, dis;

  while(fabs(lo - r) >= EPSILON){
    mid = (lo + r)/2.0;
    dis = dijkstra(mid);
    if(fabs(dis - t) >= EPSILON and dis > t) lo = mid;
    else r = mid;
  }

  cout << fixed << lo << "\n";

  return 0;
}