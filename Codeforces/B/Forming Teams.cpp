#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int dfs(vector<vector<int> > &v, vector<int> &seen, int nodo, int r, int bef){
  int n = v[nodo].size(), a = MINF;
  seen[nodo] = 0;
  
  FOR(i, 0, n){
    if(seen[v[nodo][i]]){
      a = dfs(v, seen, v[nodo][i], r, nodo);
      return a+1;
    }else if(v[nodo][i] == r and bef != v[nodo][i]) return 1;
  }
  
  return MINF;
}

int main(){
  int n, m, ans = 0, x, y;
  cin >> n >> m;
  vector<vector<int> > v(n + 1);
  vector<int> seen(n+1, 1);
  
  FOR(i, 0, m){
    cin >> x >> y;
    v[x].PB(y);
    v[y].PB(x);
  }
  
  FOR(i, 1, n+1){
    if(seen[i]){
      x = dfs(v, seen, i, i, 0);
      if(x%2 and x > 2) ans++;
    }
  }
  
  if((n - ans)%2) ans++;
  cout << ans << "\n";
  
  return 0;
}