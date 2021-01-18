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
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define MAX 150

using namespace std;

ll dp[16][MAX][2][2];

ll f(int i, int sum, int e, int &id, string &n){
  if(i == n.size()) return sum;
  if(dp[i][sum][e][id] != -1) return dp[i][sum][e][id];
  
  ll res = 0;
  int ne, lim;
  
  if(e) lim = 9;
  else lim = n[i] - '0';
  
  FOR(j, 0, lim + 1){
    ne = e;
    if(e == 0 and j < lim) ne = 1;
    
    res += f(i + 1, sum + j, ne, id, n);
  }
  
  return dp[i][sum][e][id] = res;
}

int main(){
  int cases, i1 = 0, i2 = 1;
  ll res, a1, a2, e;
  string a, b;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> e >> b;
    e--;
    a = to_string(e);
    
    FOR(i, 0, b.size()){
      FOR(j, 0, MAX){
        FOR(k, 0, 2){
          FOR(l, 0, 2) dp[i][j][k][l] = -1;
        }
      }
    }
    
    a1 = f(0, 0, 0, i1, b);
    a2 = f(0, 0, 0, i2, a);
    res = a1 - a2;
    
    cout << res << "\n";
  }

  return 0;
}