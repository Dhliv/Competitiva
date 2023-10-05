#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

ll n;
vector<vector<int>> g;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int find(int x, vector<ll> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void merge(int a, int b, vector<ll> &p, vector<ll> &s){
  int fa = find(a, p), fb = find(b, p);
  if(fa == fb) return;

  if(s[fa] > s[fb]) swap(fa, fb);
  p[fa] = fb;
  s[fb] += s[fa];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(5);

  int m; cin >> n >> m;
  n++;
  vector<int> times(n);
  g.assign(n, {});

  int x, y;
  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  find_bridges();

  vector<ll> p(n), s(n, 1);
  FOR(i, 0, n) p[i] = i;

  FOR(i, 1, n) merge(tin[i], low[i], p, s);

  ll ans = 0, total = 0;
  total = ((n - 1)*(n - 2))/2;
  FOR(i, 1, n){
    x = find(i, p);
    if(i != x or s[x] == 1) continue;
    ans += (s[i]*(s[i] - 1))/2;
  }

  ans = total - ans;
  ld a = ans, b = total;
  cout << fixed << a/b << "\n";

  return 0;
}