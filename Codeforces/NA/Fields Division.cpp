#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y; cin >> n >> m;
  vector<vector<int> > g(n + 1);

  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  vector<int> seen(n + 1, INF);
  deque<int> q;
  q.PB(n - 1);
  seen[n - 1] = 0;

  while(!q.empty()) {
    x = q.F();
    q.P_F();

    for(const auto y: g[x]) {
      if(y == n or seen[y] != INF) continue;

      seen[y] = 0;
      q.PB(y);
    }
  }

  FOR(i, 1, n + 1){
    if(seen[i]) cout << "A";
    else cout << "B";
  }

  cout << "\n";

  return 0;
}
