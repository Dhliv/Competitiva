#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

using namespace std;

int tag;
vector<vector<int> > g[2];
deque<int> ts;
vector<int> v;

void dfs(int &id, int x){
  v[x] = 1;
  for(auto y: g[id][x]){
    if(!v[y]) dfs(id, y);
  }

  if(id == 0) ts.PF(x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, z = 0, u = 1;
  
  string a, b;

  while(cin >> n >> m, n + m){
    getline(cin, a);
    map<string, int> id;

    FOR(i, 0, n){
      getline(cin, a);
      id.insert(MP(a, i));
    }

    g[0].assign(n, {});
    g[1].assign(n, {});
    v.assign(n, 0);

    FOR(i, 0, m){
      getline(cin, a);
      getline(cin, b);
      x = id[a];
      y = id[b];

      g[0][x].PB(y);
      g[1][y].PB(x);
    }

    FOR(i, 0, n) if(!v[i]) dfs(z, i);
    tag = 0;
    FOR(i, 0, n) v[i] = 0;

    while(!ts.empty()){
      x = ts.F();
      ts.P_F();
      if(!v[x]){
        dfs(u, x);
        tag++;
      }
    }

    cout << tag << "\n";
  }

  return 0;
}