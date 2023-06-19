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

const ld EPSILON = 0.0000001;

struct edge {
  int y, w;

  edge(){}

  edge(int y, int w) {
    this->y = y;
    this->w = w;
  }
};

bool able;
int ini, fin;
vector<vector<edge> > g;
int n;

void dfs(int x, set<int> &s, vector<bool> &seen, bool ini, int val){
  seen[x] = true;
  int ax;

  for(const edge &e: g[x]){
    if(seen[e.y]) continue;
    ax = val ^ e.w;
    if(ini and e.y == fin){
      if(ax != 0) continue;
      able = true;
    }

    if(ini) s.insert(ax);
    else able |= (s.find(ax) != s.end());
    dfs(e.y, s, seen, ini, ax);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int x, y, w;

  while(t--){
    cin >> n >> ini >> fin;
    able = false;
    set<int> s;
    s.insert(0);
    g.assign(n + 1, {});
    vector<bool> seen(n + 1);
    FOR(i, 0, n - 1){
      cin >> x >> y >> w;
      g[x].PB(edge(y, w));
      g[y].PB(edge(x, w));
    }

    dfs(ini, s, seen, true, 0);
    FOR(i, 0, n + 1) seen[i] = 0;
    if(!able) dfs(fin, s, seen, false, 0);

    cout << (able ? "YES" : "NO") << "\n";
  }
 
  return 0;
}