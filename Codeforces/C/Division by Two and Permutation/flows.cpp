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

int totalFlow;

int BFS(int &ori, int &dest, vector<int> &seen, vector<vector<int> > &g, vector<vector<int> > &flows){
  int x;

  FOR(i, 0, g.size()) seen[i] = INF;

  seen[ori] = 0;
  deque<int> p;
  p.PB(ori);

  while(!p.empty()){
    x = p.F();
    p.P_F();

    for(auto y: g[x]){
      if(flows[x][y] == 0 or seen[y] != INF) continue;
      seen[y] = seen[x] + 1;
      p.PB(y);
    }
  }

  return seen[dest];
}

int DFS(int ori, int &dest, vector<int> &seen, vector<vector<int> > &g, vector<vector<int> > &flows){
  int flow = INF;

  for(auto y: g[ori]){
    if(seen[ori] + 1 == seen[y] and flows[ori][y]){
      if(y == dest){
        flow = 1;
        totalFlow++;
        flows[ori][y] = 0;
        flows[y][ori] = 1;
        return flow;
      }else{
        flow = DFS(y, dest, seen, g, flows);

        if(flow != INF){
          flows[ori][y] = 0;
          flows[y][ori] = 1;
          return flow;
        }
      }
    }
  }

  return flow;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x, sz, ori, dest, y; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    sz = 2*n + 2;
    vector<vector<int> > flows(sz, vector<int> (sz)), g(sz);
    vector<int> seen(sz, INF);
    ori = 0;
    dest = sz - 1;
    totalFlow = 0;

    FOR(i, 1, n + 1){
      cin >> x;
      y = i + n;
      g[i].PB(dest);
      flows[i][dest] = 1;
      g[ori].PB(y);
      flows[ori][y] = 1;

      while(x > n) x /= 2;

      while(x >= 1){
        g[y].PB(x);
        flows[y][x] = 1;
        x /= 2;
      }
    }

    while(BFS(ori, dest, seen, g, flows) != INF){
      while(DFS(ori, dest, seen, g, flows) != INF){}
    }

    if(totalFlow != n) cout << "no\n";
    else cout << "yes\n";
  }
  
  return 0;
}
