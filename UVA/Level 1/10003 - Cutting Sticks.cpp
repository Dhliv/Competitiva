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
#define MAX 52

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int> > dp(MAX, vector<int> (MAX)), cost(MAX, vector<int> (MAX)), opt(MAX, vector<int> (MAX));
  int l, n, mini, c, val, pos;

  while(cin >> l, l){
    cin >> n;
    vector<int> cuts(n + 2); FOR(i, 1, n + 1) cin >> cuts[i];
    cuts[0] = 0; cuts[n + 1] = l;

    FOR(i, 0, n + 2){
      FOR(j, i + 1, n + 2){
        dp[i][j] = 0;
        opt[i][j] = 0;
      }

      FOR(j, i + 2, n + 2) {
        cost[i][j] = cuts[j] - cuts[i];
      }
    }

    FOR(i, 0, n){
      dp[i][i + 2] = cost[i][i + 2];
      opt[i][i + 2] = i + 1;
    }

    FORI(i, n - 2, 0){
      FOR(j, i + 3, n + 2){
        mini = INT_MAX;
        c = cost[i][j];
        pos = -1;

        FOR(k, opt[i][j - 1], opt[i + 1][j] + 1){
          val = dp[i][k] + dp[k][j];
          if(val < mini){
            mini = val;
            pos = k;
          }
        }

        opt[i][j] = pos;
        mini += c;
        dp[i][j] = mini;
      }
    }

    cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
  }
 
  return 0;
}