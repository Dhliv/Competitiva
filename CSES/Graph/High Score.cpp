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
const ll MAX = 1000000000000000000;

struct edge{
  int x, y;
  ll w;

  edge(){}
  edge(int x, int y, ll w) : x(x), y(y), w(w) {}
};

int n;
vector<ll> s;
vector<edge> edges;

void addEdge(int x, int y, ll w){
  edges.PB(edge(x, y, w));
}

void bellman(){
  FOR(i, 1, n){  // Relax n - 1 times
    for(const edge &e: edges){
      if(s[e.x] == MAX) continue;
      s[e.y] = min(s[e.y], s[e.x] + e.w);
      s[e.y] = max(-MAX, s[e.y]);
    }
  }

  FOR(i, 1, n){ // Deal with all neg cycles.
    for(const edge &e: edges){
      if(s[e.x] == MAX) continue;
      s[e.y] = max(-MAX, s[e.y]);
      if(s[e.x] + e.w < s[e.y]) s[e.y] = -MAX;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, x, y; cin >> n >> m;
  ll w;
  s.assign(n + 1, MAX);

  FOR(i, 0, m){
    cin >> x >> y >> w;
    addEdge(x, y, -w);
  }

  s[1] = 0;
  bellman();

  bool able = true;
  if(n == 1){
    for(const edge &e: edges) if(e.w < 0) able = false;
  }

  if(s[n] == -MAX or !able) cout << "-1\n";
  else cout << -s[n] << "\n";

  return 0;
}