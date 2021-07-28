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

deque<int> ts;
vector<vector<int> > g;
vector<int> v;

void dfs(int id, int x){
	v[x] = 1;

	for(auto y: g[x]){
		if(!v[y]) dfs(id, y);
	}

	if(!id) ts.PF(x);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, x, y, z = 0, u = 1, ans, id = 1;
  cin >> t;

  FOR(ab, 0, t){
  	cin >> n >> m;
  	g.assign(n + 1, {});
  	v.assign(n + 1, 0);

  	FOR(i, 0, m){
  		cin >> x >> y;
  		g[x].PB(y);
  	}

  	FOR(i, 1, n + 1){
  		if(!v[i]) dfs(z, i);
  	}

  	FOR(i, 1, n + 1) v[i] = 0;

  	ans = 0;
  	while(!ts.empty()){
  		x = ts.F();
  		ts.P_F();

  		if(!v[x]){
  			dfs(u, x);
  			ans++;
  		}
  	}

  	cout << "Case " << id++ << ": ";
  	cout << ans << "\n";
  }

  return 0;
}
