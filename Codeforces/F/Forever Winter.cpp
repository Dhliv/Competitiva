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

int bfs(int ori, vector<vector<int> > &grafo, vector<int> &sn){
  sn[ori] = 0;
  deque<int> q(1, ori);
  int x, maxi = 0, nd = ori;

  while(!q.empty()){
    x = q.F(); q.P_F();

    for(const int &y: grafo[x]){
      if(sn[y] != INF) continue;
      sn[y] = sn[x] + 1;
      if(sn[y] > maxi){
        maxi = sn[y];
        nd = y;
      }

      q.PB(y);
    }
  }

  return nd;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, m, root, x, y;

  while(t--){
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    FOR(i, 0, m){
      cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
    }

    vector<int> s1(n + 1, INF), s2(n + 1, INF), s3(n + 1, INF);
    x = bfs(1, g, s1);
    x = bfs(x, g, s2);
    x = bfs(x, g, s3);

    FOR(i, 1, n + 1){
      if(s2[i] == 2 and s3[i] == 2){
        root = i;
        break;
      }
    }

    x = g[root].size();
    y = g[g[root][0]].size() - 1;

    cout << x << " " << y << "\n";
  }
 
  return 0;
}