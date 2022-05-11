#include <bits/stdc++.h>
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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define MAX 10001
#define MOD 1000000007
 
using namespace std;

ll dp[MAX];
int n, k, s;
vector<int> p;

ll f(int i){
  if(i == n) return 1;
  ll &ans = dp[i];
  if(ans != -1) return ans;

  ans = 0;
  int pos = (upper_bound(p.begin(), p.end(), p[i] + k) - p.begin()) - 1;
  pos = (pos - i + 1 > s) ? i + s - 1 : pos;

  FORI(j, pos, i) ans = (ans + f(j + 1))%MOD;

  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> n >> k >> s;
  p.assign(n, 0); FOR(i, 0, n) cin >> p[i];
  sort(p.begin(), p.end());
  p.PB(INF);

  cout << f(0) << "\n";

  return 0;
}