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

struct edge{
  int x, y, w;

  edge(){}
  edge(int x, int y, int w): x(x), y(y), w(w){}
};

int n, m, k;
vector<edge> edges, edgesI;
vector<vector<int> > grafo, grafoI;

void dijkstra(int ori, vector<vector<ll> > &seen, bool inv){
  vector<vector<int> > vistos(n, vector<int> (k + 1, 0));
  priority_queue<pair<ll, pair<int, int> > > pq;
  seen[ori][0] = 0;
  pq.push(MP(0, MP(ori, 0)));
  ll w;
  edge e;

  while(!pq.empty()){
    auto p = pq.top().s; pq.pop();

    if(vistos[p.f][p.s]) continue;
    vistos[p.f][p.s] = 1;

    for(auto &e_id: (inv ? grafoI[p.f] : grafo[p.f])){
      e = (inv ? edgesI[e_id] : edges[e_id]);

      w = seen[p.f][p.s];
      if(!vistos[e.y][p.s] and seen[e.y][p.s] > w + e.w){
        seen[e.y][p.s] = w + e.w;
        pq.push(MP(-(w + e.w), MP(e.y, p.s)));
      }

      if(p.s < k and !vistos[e.y][p.s + 1] and seen[e.y][p.s + 1] > w){
        seen[e.y][p.s + 1] = w;
        pq.push(MP(-w, MP(e.y, p.s + 1)));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  int x, y, w, a, b; cin >> a >> b >> k;
  edges.assign(0, {});
  edgesI.assign(0, {});
  grafo.assign(n, {});
  grafoI.assign(n, {});

  FOR(i, 0, m){
    cin >> x >> y >> w;
    grafo[x].PB(edges.size());
    grafoI[y].PB(edgesI.size());
    edges.PB(edge(x, y, w));
    edgesI.PB(edge(y, x, w));
  }

  vector<vector<ll > > seen1(n, vector<ll> (k + 1, INF)), seen2(n, vector<ll> (k + 1, INF));
  vector<vector<ll > > seen1I(n, vector<ll> (k + 1, INF)), seen2I(n, vector<ll> (k + 1, INF));

  dijkstra(a, seen1, false);
  dijkstra(a, seen1I, true);
  dijkstra(b, seen2, false);
  dijkstra(b, seen2I, true);

  ll ans = LLONG_MAX, aux1, aux2;
  int city = -1;

  FOR(i, 0, n){
    if(a == i or b == i) continue;

    aux1 = aux2 = LLONG_MAX;
    FOR(j, 0, k + 1){
      FOR(j2, 0, k + 1){
        if(j + j2 > k) continue;
        if(aux1 > (seen1[i][j] + seen1I[i][j2])) aux1 = seen1[i][j] + seen1I[i][j2];
        if(aux2 > (seen2[i][j] + seen2I[i][j2])) aux2 = seen2[i][j] + seen2I[i][j2];
      }
    }

    if(aux1 >= INF or aux2 >= INF) continue;
    if(ans > aux1 + aux2){
      ans = aux2 + aux1;
      city = i;
    }
  }

  if(city != -1) cout << city << " " << ans << "\n";
  else cout << ">:(\n";

  return 0;
}