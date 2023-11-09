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

  string s; cin >> s;
  int n = s.size();
  vector<vector<int> > isP(n, vector<int> (n));

  // palindromos impares
  FOR(i, 0, n){
    int l = i - 1, r = i + 1;
    isP[i][i] = 1;

    while(l >= 0 and r < n){
      if(s[l] != s[r]) break;
      isP[l--][r++] = 1;
    }
  }

  // pares
  FOR(i, 1, n){
    int l = i - 1, r = i;
    while(l >= 0 and r < n){
      if(s[l] != s[r]) break;
      isP[l--][r++] = 1;
    }
  }

  vector<vector<int> > dp(MAX, vector<int> (MAX));
  FOR(i, 0, n) dp[i][i] = 1;

  FORI(i, n - 1, 0){
    FOR(j, i + 1, n){
      dp[i][j] = isP[i][j] + dp[i + 1][j] + dp[i][j - 1] - (j - 1 > i ? dp[i + 1][j - 1] : 0);
    }
  }

  

  int q; cin >> q;
  int l, r;
  FOR(i, 0, q){
    cin >> l >> r;
    l--; r--;
    cout << dp[l][r] << "\n";
  }

  return 0;
}