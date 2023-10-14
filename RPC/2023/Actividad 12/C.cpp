#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.000000001;

ll dp[52][52][52][22];
int n;
ll p[52];

ll f(int i, int last, int blast, int k){
  if(k == 0) return 1;
  if(i == n + 1 and k != 0) return 0;
  if(i == n + 1) return 1;

  ll &ans = dp[i][last][blast][k];
  if(ans != -1) return ans;

  ans = 0;
  ans += f(i + 1, last, blast, k);
  if(last != 0 and blast != 0){
    if(p[i] <= p[last] + p[blast]) ans += f(i + 1, i, last, k - 1);
  }else if(blast != 0) ans += f(i + 1, i, last, k - 1);
  else ans += f(i + 1, i, last, k - 1);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int k; cin >> n >> k;
  p[0] = -1;
  FOR(i, 1, n + 1) cin >> p[i];
  sort(p, p + n + 1);

  memset(dp, -1, sizeof(dp));

  cout << f(1, 0, 0, k) << "\n";

  return 0;
}