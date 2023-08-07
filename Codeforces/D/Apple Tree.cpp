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

void dfs(int x, vector<vector<int> > &g, vector<ll> &leafs){
  if(g[x].size() == 0){
    leafs[x]++;
    return;
  }

  for(const int &y: g[x]){
    dfs(y, g, leafs);
    leafs[x] += leafs[y];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, x, y, qr;

  while(t--){
    cin >> n;
    vector<vector<int> > g(n + 1), tree(n + 1);
    FOR(i, 0, n - 1){
      cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
    }

    vector<bool> seen(n + 1);
    seen[1] = 1;
    deque<int> q(1, 1);
    while(q.size()){
      x = q.F(); q.P_F();

      for(const int &y: g[x]){
        if(seen[y]) continue;
        seen[y] = 1;
        tree[x].PB(y);
        q.PB(y);
      }
    }

    vector<ll> leafs(n + 1);
    dfs(1, tree, leafs);
    
    cin >> qr;
    FOR(i, 0, qr){
      cin >> x >> y;
      cout << leafs[x]*leafs[y] << "\n";
    }
  }
 
  return 0;
}