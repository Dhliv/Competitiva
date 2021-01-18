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

int n, m, d;
int dp[200][20][11];

int f(int i, int e, int w, deque<int> &q){
  if(i == n and w == m and e == 0) return 1;
  if(w == m and e == 0) return 1;
  if(i == n or w == m) return 0;
  int &ans = dp[i][e][w];
  if(ans != -1) return ans;
  
  int res;
  res = f(i + 1, e, w, q) + f(i + 1, (e + q[i]%d + d)%d, w + 1, q);
  
  return ans = res;
}

int main(){
  int q, cont = 1;
  
  while(cin >> n >> q, n + q){
    cout << "SET " << cont++ << ":\n";
    deque<int> data(n);
    
    FOR(i, 0, n) cin >> data[i];
    
    FOR(i, 0, q){
      cin >> d >> m;
      memset(dp, -1, sizeof(dp));
      cout << "QUERY " << i + 1 << ": " << f(0, 0, 0, data) << "\n";
    }
  }
  
  return 0;
}