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

int aux, k;
string a, b;
int dp[10][91][91][2];

int f(int i, int s, int e, int m, string &n){
  if(i == n.size() and e == 0 and s%k == 0) return 1;
  if(i == n.size()) return 0;
  if(dp[i][s][e][m] != -1) return dp[i][s][e][m];
  
  int lim, ne = e*10, nm, res = 0;
  
  if(m) lim = 9;
  else lim = n[i] - '0';
  
  FOR(j, 0, lim + 1){
    nm = m;
    if(m == 0 and j < lim) nm = 1;
    
    res += f(i + 1, s + j, (ne + j)%k, nm, n);
  }
  
  return dp[i][s][e][m] = res;
}

int main(){
  int cases, res, a1, a2;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cout << "Case " << ab + 1 << ": ";
    cin >> aux >> b >> k;
    aux--;
    a = to_string(aux);
    
    if(k > 90) cout << "0\n";
    else{
      memset(dp, -1, sizeof(dp));
      a1 = f(0, 0, 0, 0, b);
      
      memset(dp, -1, sizeof(dp));
      a2 = f(0, 0, 0, 0, a);
      
      res = a1 - a2;
      cout << res << "\n";
    }
  }
  
  return 0;
}