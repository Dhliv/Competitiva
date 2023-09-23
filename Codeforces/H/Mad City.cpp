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

void dijkstra(int ini, vector<vector<int> > &g, vector<vector<int> > &seen){
  int x;
  priority_queue<pair<int, int> > pq;
  pq.push(MP(0, ini));
  pq.push(MP(-1, ini));
  vector<vector<int> > vis(g.size(), vector<int> (2));
  seen[ini][0] = 0;
  seen[ini][1] = 1;

  int val, w;
  while(!pq.empty()){
    x = pq.top().s;
    val = -pq.top().f;
    pq.pop();
    if(vis[x][val%2]) continue;
    vis[x][val%2] = 1;

    for(const int &y: g[x]){
      if(vis[y][(val + 1)%2]) continue;
      w = seen[x][val%2] + 1;
      if(seen[y][(val + 1)%2] > w){
        seen[y][(val + 1)%2] = w;
        pq.push(MP(-w, y));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, a, b, x, y;

  while(t--){
    cin >> n >> a >> b;
    vector<vector<int> > g(n + 1), s1(n + 1, vector<int> (2, INF)), s2(n + 1, vector<int> (2, INF));
    vector<int> in(n + 1);
    FOR(i, 0, n){
      cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
      in[x]++; in[y]++;
    }

    dijkstra(a, g, s1);
    dijkstra(b, g, s2);

    vector<int> couldUse(n + 1, 1);
    deque<int> q;
    FOR(i, 1, n + 1) if(in[i] == 1) q.PB(i);

    while(!q.empty()){
      x = q.F(); q.P_F();
      couldUse[x] = 0;

      for(const int &y: g[x]){
        in[y]--;
        if(in[y] == 1) q.PB(y);
      }
    }

    bool able = false;
    FOR(i, 1, n + 1){
      if(!couldUse[i]) continue;
      if(s2[i][0] < s1[i][0] or s2[i][1] < s1[i][1]){
        able = true;
        break;
      }
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}