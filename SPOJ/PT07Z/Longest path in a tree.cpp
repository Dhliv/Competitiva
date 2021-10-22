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

pair<int, int> dfs(int x, vector<vector<int> > &g, vector<pair<int, int> > &s, int father){
  pair<int, int> &ans = s[x], aux;
  if(s[x].f != -1) return s[x];
  ans = MP(x, 0);

  for(int y : g[x]){
    if(y == father) continue;
    aux = dfs(y, g, s, x);
    if(ans.s < aux.s) ans = aux;
  }

  ans.s++;
  return ans;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y, ans;
  cin >> n;

  vector<vector<int> > g(n + 1);

  FOR(i, 1, n){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  vector<pair<int, int> > s(n + 1, MP(-1, -1)), neoS(n + 1, MP(-1, -1));

  x = dfs(1, g, s, -1).f;
  ans = dfs(x, g, neoS, -1).s - 1;

  cout << ans << "\n";

  return 0;
}