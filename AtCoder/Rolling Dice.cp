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

int dp[101][1001], a, b;

int f(int i, int s){
  if(i > a) return -1;
  int &ans = dp[i][s];
  
  if(ans != -1) return ans;
  
  ans = 1;
  FOR(j, 1, 7) f(i + 1, s + j);
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> a >> b;
  memset(dp, -1, sizeof(dp));
  
  f(0, 0);
  
  cout << ((dp[a][b] == -1) ? "No" : "Yes") << "\n";

  return 0;
}