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
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, ori, dest;
  cin >> n >> m;
  vector<vector<int> > g(n + 1);
  vector<int> s(n + 1, INF), p(n + 1, -1);

  FOR(i, 0, m){
    cin >> x >> y;
    g[x].PB(y);
    g[y].PB(x);
  }

  ori = 1; dest = n;
  deque<int> q;
  s[ori] = 0;
  q.PB(ori);

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(int y: g[x]){
      if(s[y] == INF){
        s[y] = s[x] + 1;
        q.PB(y);
        p[y] = x;
      }
    }
  }

  if(s[dest] == INF) cout << "IMPOSSIBLE\n";
  else{
    deque<int> ans;
    x = dest;
    while(p[x] != -1){
      ans.PF(x);
      x = p[x];
    }

    cout << ans.size() + 1 << "\n";
    cout << ori;
    FOR(i, 0, ans.size()) cout << " " << ans[i];
    cout << "\n";
  }
  
  return 0;
}
