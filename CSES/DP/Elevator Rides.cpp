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

vector<pair<int, int> > dp(1 << 20, MP(20, INF));
int n, lim, w[20], all;

pair<int, int> get(pair<int, int> &a, pair<int, int> &b){
  if(a.f < b.f) return a;
  else if(a.f == b.f){
    if(a.s < b.s) return a;
  }
  return b;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> lim;
  FOR(i, 0, n) cin >> w[i];
  all = (1 << n) - 1;

  deque<int> q;
  q.PB(0);
  dp[0] = MP(1, 0);
  vector<bool> s(all + 1, 0);
  pair<int, int> yp;
  int sum, x, y;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    FOR(i, 0, n){
      if(x ^ 1 << i){
        y = x | 1 << i;
        sum = dp[x].s + w[i];
        if(sum > lim) yp = MP(dp[x].f + 1, w[i]);
        else yp = MP(dp[x].f, sum);

        dp[y] = get(dp[y], yp);
        if(!s[y]){
          s[y] = 1;
          q.PB(y);
        }
      }
    }
  }

  cout << dp[all].f << "\n";

  return 0;
}
