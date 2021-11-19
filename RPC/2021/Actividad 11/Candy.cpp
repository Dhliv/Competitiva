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

  ll n, m, x, y, c, w, ori, dest, d, ax;
  cin >> n >> m;
  vector<vector<pair<ll, ll> > > g(n + 1);

  cin >> ori >> dest >> d;

  FOR(i, 0, m){
    cin >> x >> y >> w;
    g[x].PB(MP(y, w));
    g[y].PB(MP(x, w));
  }

  vector<ll> s(n + 1, 0);
  vector<bool> v(n + 1);
  s[ori] = d;
  priority_queue<pair<ll, ll> > q;
  q.push(MP(d, ori));

  while(!q.empty()){
    x = q.top().s;
    ax = q.top().f;
    q.pop();

    if(v[x]) continue;
    v[x] = 1;

    for(auto p : g[x]){
      if(v[p.f]) continue;
      c = p.s * ax;
      w = ax - (c/100 + (c%100 > 0 ? 1 : 0));

      if(s[p.f] < w){
        s[p.f] = w;
        q.push(MP(w, p.f));
      }
    }
  }

  cout << s[dest] << "\n";
  
  return 0;
}