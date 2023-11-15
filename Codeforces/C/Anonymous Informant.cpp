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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int offset, x, n, k;

  while(t--){
    cin >> n >> k;
    vector<int> p(n); FOR(i, 0, n) cin >> p[i];
    vector<int> ans(n);

    offset = 0;
    x = n - 1;
    vector<int> dp(n);
    bool able = true;
    FOR(i, 0, k){
      if(dp[x]) break;
      dp[x] = 1;
      int a = p[x];
      if(a > n){
        able = false;
        break;
      }
      offset = (offset + a)%n;
      x = n - 1 - offset;
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}