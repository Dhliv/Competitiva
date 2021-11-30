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
#define MOD 1000000007
 
using namespace std;

int look(int &v, deque<pair<int, ll> > &u){
  int l = 0, r = u.size() - 2, m;

  while(l <= r){
    m = (l + r)/2;

    if(u[m].f >= v) r = m - 1;
    else l = m + 1;
  }

  return l;
}

ll calculate(ll p){
  if(p == 0) return 1;

  ll dp[31], ans;
  dp[0] = 2;
  FOR(i, 1, 31) dp[i] = (dp[i - 1]*dp[i - 1])%MOD;

  deque<int> pot;
  FOR(i, 0, 31){
    if(p & (1 << i)) pot.PB(i);
  }

  ans = dp[pot.F()];
  pot.P_F();

  while(!pot.empty()){
    ans = (ans*dp[pot.F()])%MOD;
    pot.P_F();
  }

  return ans;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, v, x;
  cin >> n >> m;
  vector<int> num(32, 1);
  num[0] = 0;
  FOR(i, 2,  32) num[i] = 2*num[i - 1];

  deque<int> q;
  deque<deque<int> > pds(m);
  vector<int> p(m);
  q.PB(0);
  FOR(i, 0, m){
    cin >> v;
    p[i] = v;
    pds[i].PB(v);
    while(v != 0) {
      q.PB(v);
      v -= num[(upper_bound(num.begin(), num.end(), v) - num.begin()) - 1];
      pds[i].PB(v);
    }
  }

  sort(q.begin(), q.end());

  deque<pair<int, ll> > u;
  x = q.F();
  u.PB(MP(x, 0));
  FOR(i, 1, q.size()){
    if(q[i] != x){
      x = q[i];
      u.PB(MP(x, 0));
    }
  }

  ll ans;
  int s;
  FOR(i, 0, m){
    v = p[i];
    ans = (calculate(n - (upper_bound(num.begin(), num.end(), v) - num.begin()) + 1) - u[look(v, u)].s + MOD)%MOD;
    s = pds[i].size() - 1;
    FOR(j, 0, s) {
      v = pds[i][j];
      x = look(v, u);
      u[x].s = (u[x].s + ans)%MOD;
    }
    u[0].s = (u[0].s + ans)%MOD;

    cout << ans << "\n";
  }
  
  return 0;
}