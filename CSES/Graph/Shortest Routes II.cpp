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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const ll MAX = 1000000000000000;
  int n, m, q; cin >> n >> m >> q;
  int x, y;
  ll w;
  vector<vector<ll> > adj(n + 1, vector<ll> (n + 1, MAX));
  FOR(i, 0, m){
    cin >> x >> y >> w;
    adj[x][y] = min(adj[x][y], w);
    adj[y][x] = min(adj[y][x], w);
  }

  FOR(i, 1, n + 1) adj[i][i] = 0;

  FOR(k, 1, n + 1){
    FOR(i, 1, n + 1){
      FOR(j, 1, n + 1){
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); 
      }
    }
  }

  FOR(i, 0, q){
    cin >> x >> y;
    cout << (adj[x][y] == MAX ? -1 : adj[x][y]) << "\n";
  }

  return 0;
}