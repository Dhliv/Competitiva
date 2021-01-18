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
#define MAX 812
 
using namespace std;

int maxi = MINF;
int n, m;
int dp[MAX][MAX][MAX], ps[MAX];

int f(int i, int j, int e){
  if(i == n) return ps[i] - ps[i - e];
  if(j == m) return INF;
  if(dp[i][j][e] != -1) return dp[i][j][e];
  
  int acum = ps[i] - ps[i - e], a1, a2;
  a1 = f(i + 1, j, e + 1);
  a2 = f(i, j + 1, 0);
  dp[i][j][e] = min(a1, max(acum, a2));
  //out << "f(" << i << ", " << j << ", " << e << ") = ";
  //cout << "min(" << a1 << ", " << "max(" << acum << ", " << a2 << ")) = ";
  //cout << dp[i][j][e] << endl;
  return dp[i][j][e];
}

int main(){
  int sum, x, y, valmax, cont, pos;
  ps[0] = 0;
  
  while(cin >> n >> m){
    sum = 0;
    maxi = MINF;
    vector<int> v(n);
    
    FOR(i, 0, n){
      cin >> v[i];
      sum += v[i];
      maxi = max(maxi, v[i]);
      FOR(j, 0, m){
        FOR(k, 0, n){
          dp[i][j][k] = -1;
        }
      }
      ps[i + 1] = sum;
    }
    
    if(m >= n){
      cout << maxi << endl;
    }
    else{
      valmax = f(0, 0, 0);
      cout << valmax << endl;
    }
  }
  
  return 0;
}