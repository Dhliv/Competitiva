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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int c[100], m, sum, val;
int dp[25001][100];

int f(int w, int i){
  if(w > val) return MINF;
  if(i == m) return w;
  if(dp[w][i] != -1) return dp[w][i];
  
  return dp[w][i] = max(f(w, i + 1), f(w + c[i], i + 1));
}

int main(){
  int cases;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> m;
    sum = 0;
    
    FOR(i, 0, m){
      cin >> c[i];
      sum += c[i];
    }
    val = sum/2;
    
    FOR(i, 0, val + 1){
      FOR(j, 0, m) dp[i][j] = -1;
    }
    
    cout << sum - 2*f(0, 0) << "\n";
  }
  
  return 0;
}