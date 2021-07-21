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

ll n, dp[1000001], c[100];
const int mod = 1000000007;

int f(int x){
	if(x < 0) return 0;
	if(x == 0) return 1;

	ll &ans = dp[x];
	if(ans != -1) return ans;

	ans = 0;
	FOR(i, 0, n) ans += f(x - c[i]);

	ans %= mod;
	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int x;
  cin >> n >> x;
  memset(dp, -1, sizeof(dp));

	FOR(i, 0, n) cin >> c[i];

	cout << f(x) << "\n";

  return 0;
}