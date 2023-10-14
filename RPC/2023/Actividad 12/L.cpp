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

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k; cin >> n >> k;
  vector<vector<int> > g(n);
  vector<int> in(n);
  int x, y;
  FOR(i, 1, n){
    cin >> y;
    g[i].PB(y);
    g[y].PB(i);
    in[i]++;
    in[y]++;
  }

  if(k + 1 == n){
    cout << "1\n";
    return 0;
  }

  vector<int> f(n), p(n);
  FOR(i, 0, n) p[i] = i;
  vector<int> sn(n, INF);
  sn[0] = 0;
  deque<int> q(1, 0);

  priority_queue<pair<int, int> > pq;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y : g[x]){
      if(sn[y] != INF) continue;
      sn[y] = sn[x] + 1;
      f[y] = x;
      q.PB(y);
      if(in[y] <= 2){
        p[y] = find(x, p);
        if(in[y] == 1) pq.push(MP(-abs(sn[y] - sn[find(x, p)]), y));
      }
    }
  }

  int val, un;
  vector<int> del(n);
  while(!pq.empty()){
    x = -pq.top().f;
    y = pq.top().s;
    pq.pop();

    if(del[y]) continue;
    val = abs(sn[y] - sn[find(p[y], p)]);
    if(val != x){
      pq.push(MP(-val, y));
      continue;
    }

    if(k < val) break;
    k -= val;
    del[y] = 1;
    un = find(p[y], p);
    while(y != un){
      y = f[y];
      if(y == 0) break;

      in[y]--;
      if(in[y] > 1){
        if(in[y] == 2) p[y] = find(f[y], p);
        break;
      }
      del[y] = 1;
    }
  }

  int ans = 0;
  FOR(i, 1, n){
    if(del[i]) continue;
    ans += (in[i] == 1);
  }

  cout << ans << "\n";

  return 0;
}