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
 
const ld EPSILON = 0.000000001;

int n;
int dp[MAX];
int p[MAX];

int f(int i){
  if(i == n) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;

  ans = 1 + f(i + 1);
  if(i + p[i] + 1 <= n){
    ans = min(ans, f(i + p[i] + 1));
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;

  while(t--){
    cin >> n;
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 0, n) dp[i] = -1;

    cout << f(0) << "\n";
  }

  return 0;
}