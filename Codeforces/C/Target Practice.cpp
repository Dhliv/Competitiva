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
 
const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n = 10;
  vector<vector<int> > score(10, vector<int> (10, 5));

  FOR(i, 0, 10){
    score[3][i] = 4;
    score[6][i] = 4;
    score[i][3] = 4;
    score[i][6] = 4;
  }

  FOR(i, 0, 10){
    score[2][i] = 3;
    score[7][i] = 3;
    score[i][2] = 3;
    score[i][7] = 3;
  }

  FOR(i, 0, 10){
    score[1][i] = 2;
    score[8][i] = 2;
    score[i][1] = 2;
    score[i][8] = 2;
  }

  FOR(i, 0, 10){
    score[0][i] = 1;
    score[9][i] = 1;
    score[i][0] = 1;
    score[i][9] = 1;
  }

  vector<string> s(10);
  while(t--){
    FOR(i, 0, n) cin >> s[i];

    int ans = 0;
    FOR(i, 0, n){
      FOR(j, 0, n){
        if(s[i][j] == '.') continue;
        ans += score[i][j];
      }
    }

    cout << ans << "\n";
  }

  return 0;
}