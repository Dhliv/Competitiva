#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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
#define MAX 1001

using namespace std;

int dp[MAX][12*MAX];
int dispensers[MAX][13];
int n;

int f(int i, int k){
  if(k == 0 or i == n) return 0;
  int &ans = dp[i][k];
  if(ans != -1) return ans;

  ans = f(i + 1, k);
  FOR(j, 0, min(12, k)){
    ans = max(ans, dispensers[i][j + 1] + f(i + 1, k - (j + 1)));
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int k;
  cin >> n >> k;

  FOR(i, 0, n){
    dispensers[i][0] = 0;
    FOR(j, 0, k + 1) dp[i][j] = -1;
  }

  FOR(i, 0, n){
    FOR(j, 1, 13){
      cin >> dispensers[i][j];
      dispensers[i][j] += dispensers[i][j - 1];
    }
  }

  cout << f(0, k) << "\n";

  return 0;
}