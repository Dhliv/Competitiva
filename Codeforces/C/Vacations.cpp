#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

int dp[100][3];
int p[100], n;

int f(int i, int l){
  if(i == n) return 0;
  int &ans = dp[i][l];
  if(ans != -1) return ans;

  ans = 0;
  switch(p[i]){
    case 0:
      ans = 1 + f(i + 1, 0);
      break;
    case 1:
      ans = l == 1 ? 1 + f(i + 1, 0) : f(i + 1, 1);
      break;
    case 2:
      ans = l == 2 ? 1 + f(i + 1, 0) : f(i + 1, 2);
      break;
    case 3:
      if(l == 0){
        ans = f(i + 1, 1);
        ans = min(ans, f(i + 1, 2));
        ans = min(ans, 1 + f(i + 1, 0));
      }else{
        ans = l == 1 ? f(i + 1, 2) : f(i + 1, 1);
        ans = min(ans, 1 + f(i + 1, 0));
      }
      break;
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, 0, n) cin >> p[i];

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << "\n";
  
  return 0;
}
