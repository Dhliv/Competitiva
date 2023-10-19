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

int n, m;
bool imp = false;
vector<int> gr, v;
vector<vector<int> > g;

void dfs(int ori, int id){
  v[ori] = 1;
  gr[ori] = id + 1;
  for(const int y: g[ori]){
    if(y == ori) continue;

    if(v[y]){
      if(id + 1 == gr[y]) imp = true;
      continue;
    }

    dfs(y, 1 - id);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  n++;
  g.assign(n, {});
  gr.assign(n, {});
  v.assign(n, {});

  int x, y;
  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  FOR(i, 1, n){
    if(v[i]) continue;
    dfs(i, 0);
  }

  if(imp) cout << "IMPOSSIBLE\n";
  else{
    FOR(i, 1, n) cout << gr[i] << " ";
    cout << "\n";
  }

  return 0;
}