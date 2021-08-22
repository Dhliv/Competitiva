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
#define MAX 5010
#define DS LLONG_MAX
 
using namespace std;

bool maxi(pair<ll, ll> &a, pair<ll, ll> &b, bool &id){
  if(id){
    if(a.f > b.f) return 1;
    return 0;
  }else{
    if(a.s > b.s) return 1;
    return 0;
  }
}

ll p[MAX], n;
pair<ll, ll> dp[MAX][MAX];

pair<ll, ll> f(int l, int r){
  if(l > r) return MP(0, 0);
  pair<ll, ll> &ans = dp[l][r], ax;
  if(ans.f != DS) return ans;

  ans = f(l + 1, r);
  ax = f(l, r - 1);

  bool tr = (r - l) & 1 == 1 ^ (n & 1 == 1);

  if(tr){
    ans.f += p[l];
    ax.f += p[r];
  }else{
    ans.s += p[l];
    ax.s += p[r];
  }
  ans = (maxi(ans, ax, tr) == 1 ? ans : ax);

  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  pair<ll, ll> pds = MP(DS, DS);

  FOR(i, 0, n + 1){
    FOR(j, i, n + 1) dp[i][j] = pds;
  }

  FOR(i, 0, n) cin >> p[i];

  cout << f(0, n - 1).f << "\n";
  
  return 0;
}
