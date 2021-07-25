#include <bits/stdc++.h>
#define INF 10000000
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
#define MAX 1000001
 
using namespace std;

int n, dp[MAX], c[MAX];

int f(int x){
  if(x < 0) return INF;
  if(x == 0) return 0;
  int &ans = dp[x];
  if(ans != -1) return ans;
  
  ans = INF;
  FOR(i, 0, n) ans = min(ans, f(x - c[i]) + 1);
  
  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int x, ans;
  cin >> n >> x;
  
  FOR(i, 0, x + 1) dp[i] = -1;
  FOR(i, 0, n) cin >> c[i];
  
  ans = f(x);
  cout << (ans == INF ? -1 : ans) << "\n";
 
  return 0;
}