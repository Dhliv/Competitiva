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

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, c, x, y, fx, fy;
  ll ans;
  cin >> n >> m;
  
  vector<int> p(n + 1);
  deque<pair<int, pair<int, int> > > q;
  
  FOR(i, 0, n + 1) p[i] = i;
  
  FOR(i, 0, m){
    cin >> x >> y;
    q.PB(MP(y, MP(0, x)));
  }
  
  FOR(i, 1, n){
    cin >> c;
    q.PB(MP(c, MP(i, i + 1)));
  }
  cin >> c;
  q.PB(MP(c, MP(n, 1)));
  
  sort(q.begin(), q.end());
  
  ans = 0;
  FOR(i, 0, q.size()){
    c = q[i].f;
    x = q[i].s.f;
    y = q[i].s.s;
    
    fx = find(x, p);
    fy = find(y, p);
    
    if(fx != fy){
      p[fx] = fy;
      ans += c;
    }
  }
  
  cout << ans << "\n";

  return 0;
}