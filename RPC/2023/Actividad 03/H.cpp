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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, tar, atlas, lat; cin >> n >> m >> tar >> atlas >> lat;
  vector<vector<int> > g(n);
  int x, y;
  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  vector<vector<int> > par(n, vector<int> (2, INF));
  deque<pair<int, int > > q(1, MP(atlas, 0));
  par[atlas][0] = 0;
  int val, nx;
  while(!q.empty()){
    x = q.F().f;
    val = q.F().s; q.P_F();
    nx = (1 + val)%2;

    for(const int &y: g[x]){
      if(par[y][nx] != INF) continue;
      par[y][nx] = 1 + par[x][val%2];
      q.PB(MP(y, nx));
    }
  }


  priority_queue<pair<int, int> > pq;
  vector<int> seen(n, INF), vis(n);
  if(par[lat][0] > 0) {
    pq.push(MP(0, lat));
    seen[lat] = 0;
  }
  while(!pq.empty()){
    x = pq.top().s;
    val = (-pq.top().f) + 1; pq.pop();
    if(vis[x]) continue;
    vis[x] = 1;
    //cout << "(" << x << ", " << val - 1 << ") ->";

    for(const int &y: g[x]){
      if((par[y][val%2] <= val and par[y][(val + 1)%2] <= val + 1) or vis[y]) continue;
      if(par[y][val%2] > val and seen[y] > val){
        seen[y] = val;
        pq.push(MP(-val, y));
        //cout << "(" << y << ", " << val << ")";
        continue;
      }

      if(seen[y] <= val + 1) continue;
      //cout << "(" << y << ", " << val + 1 << ")";
      seen[y] = val + 1;
      pq.push(MP(-(val + 1), y));
    }

    //cout << "\n";
  }

  if(seen[tar] == INF) cout << "death\n";
  else cout << seen[tar] << "\n";
 
  return 0;
}