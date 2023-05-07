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
#define MAX 200005

using namespace std;

const ld EPSILON = 0.0000001;
const int mod = 1000000007;
ll dp[MAX][64];
int nums[MAX];
int n, k;

int numbits(int x){
  int n = 0;
  FOR(i, 0, 6){
    if(x & (1 << i)) n++;
  }

  return n;
}

ll f(int i, int x){
  if(i == n) return 0;
  ll &ans = dp[i][x];
  if(ans != -1) return ans;
  ans = 0;

  ans = f(i + 1, x);
  int y = x & nums[i];
  ans = (ans + ((numbits(y) == k) + f(i + 1, y)))%mod;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  while(t--){
    cin >> n >> k;
    FOR(i, 0, n){
      FOR(j, 0, 64) dp[i][j] = -1;
      cin >> nums[i];
    }

    ll ans = 0;
    FOR(i, 0, n){
      ans = (ans + f(i + 1, nums[i]) + (k == numbits(nums[i])))%mod;
    }

    cout << ans << "\n";
  }
 
  return 0;
}