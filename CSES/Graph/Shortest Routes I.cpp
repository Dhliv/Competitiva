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

vector<edge> edges;
vector<vector<int> > g;

void addEdge(int x, int y, ll w){
  g[x].PB(edges.size());
  edges.PB(edge(x, y, w));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m; cin >> n >> m;
  g.assign(n + 1, {});
  int x, y;
  ll w;
  FOR(i, 0, m){
    cin >> x >> y >> w;
    addEdge(x, y, w);
  }

  vector<ll> s(n + 1, LLONG_MAX);
  vector<bool> v(n + 1);
  priority_queue<pair<ll, int> > pq;
  s[1] = 0;
  pq.push(MP(0, 1));

  while(!pq.empty()){
    x = pq.top().s;
    pq.pop();

    if(v[x]) continue;
    v[x] = 1;

    for(const int &e_id: g[x]){
      edge &e = edges[e_id];
      y = e.y;
      if(v[y]) continue;
      w = s[x] + e.w;
      if(w >= s[y]) continue;
      s[y] = w;
      pq.push(MP(-w, y));
    }
  }

  FOR(i, 1, n + 1) cout << s[i] << " ";
  cout << "\n";

  return 0;
}