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
#define MAX 10001
 
using namespace std;

int n, m;
int dp[MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  int x, y;

  deque<int> p;
  dp[n] = 0;
  p.PB(n);

  while(!p.empty()){
    x = p.F();
    p.P_F();

    y = x*2;
    if(y < MAX){
      if(dp[y] == -1){
        dp[y] = dp[x] + 1;
        p.PB(y);
      }
    }

    y = x - 1;
    if(y >= 0){
      if(dp[y] == -1){
        dp[y] = dp[x] + 1;
        p.PB(y);
      }
    }
  }

  cout << dp[m] << "\n";

  return 0;
}
