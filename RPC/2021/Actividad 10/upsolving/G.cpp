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

int dp[6][6*100];

int f(int i, int k, vector<int> &p){
  if(i == 6) return 0;
  int &ans = dp[i][k];

  if(p[i] > k) ans = f(i + 1, k, p);
  else{
    ans = p[i] + f(i + 1, k - p[i], p);
    ans = max(ans, f(i + 1, k, p));
  }

  return ans;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, s;
  cin >> t;

  FOR(ab, 0, t){
    memset(dp, -1, sizeof(dp));
    vector<int> p(6);
    s = 0;
    FOR(i, 0, 6){
      cin >> p[i];
      s += p[i];
    }

    if(s & 1 or f(0, s/2, p) != s/2) cout << "Tobby no puede cruzar\n";
    else cout << "Tobby puede cruzar\n"; 
  }

  return 0;
}