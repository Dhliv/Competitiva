#include <bits/stdc++.h>
#define INF INT_MAX
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
#define MAX 255

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int> > dp(MAX, vector<int> (MAX)), opt(MAX, vector<int> (MAX)), cost(MAX, vector<int> (MAX));
  vector<int> ps(MAX);

  int n, mini, val, pos;
  while(cin >> n){
    FOR(i, 0, n){
      cin >> ps[i + 1];
      ps[i + 1] += ps[i];
    }

    FOR(i, 1, n + 1){
      opt[i][i] = i;
      FOR(j, 1, n + 1) dp[i][j] = 0;
      FOR(j, i, n + 1) cost[i][j] = ps[j] - ps[i - 1];
    }

    FORI(i, n - 1, 1){
      FOR(j, i + 1, n + 1){
        mini = INF;
        pos = -1;
        FOR(k, opt[i][j - 1], opt[i + 1][j] + 1){
          val = 0;
          if(k > i) val += dp[i][k - 1] + cost[i][k - 1];
          if(k < j) val += dp[k + 1][j] + cost[k + 1][j];
          if(mini > val){
            mini = val;
            pos = k;
          }
        }

        opt[i][j] = pos;
        dp[i][j] = mini;
      }
    }

    cout << dp[1][n] << "\n";
  }
 
  return 0;
}