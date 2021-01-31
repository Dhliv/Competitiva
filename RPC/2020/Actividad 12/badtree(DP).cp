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
#define MAX 102
 
using namespace std;

__int128 dp[MAX][MAX][MAX], n, k;

__int128 f(int pi, int pd, int ne){
  if(dp[pi][pd][ne] != -1) return dp[pi][pd][ne];
  if(pi == pd){
    dp[pi][pd][ne] = 1;
    return 1;
  }
  
  return dp[pi][pd][ne] = f(pi + 1, pd, pi) + f(pi, pd - 1, pd);
}

void search(int pi, int pd, __int128 acum){
  if(pi == pd){
    cout << pi + 1 << "\n";
    return;
  }
  
  if(k <= acum + dp[pi + 1][pd][pi]){
    cout << pi + 1 << " ";
    search(pi + 1, pd, acum);
  }else{
    cout << pd + 1 << " ";
    search(pi, pd - 1, acum + dp[pi][pd - 1][pd]);
  }
}

int main(){
  ll neo, keo;
  cin >> neo >> keo;
  n = neo;
  k = keo;
  
  FOR(i, 0, n){
    FOR(j, 0, n){
      FOR(k, 0, n) dp[i][j][k] = __int128(-1);
    }
  }
  
  if(neo == 1){
    if(keo == 1) cout << "1\n";
    else cout << "-1\n";
  }else{
    __int128 a, b;
    a = f(1, neo - 1, 0);
    b = f(0, neo - 2, neo - 1);
    
    if(k > (a + b)) cout << "-1\n";
    else search(0, neo - 1, 0);
  }
  
  return 0;
}