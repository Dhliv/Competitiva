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
#define MAX 10000
 
using namespace std;

int n, k;
ll dp[60][60][MAX];

ll f(int i, int nb, int acum){
  if(i == n and acum == k) return 1;
  if(i == n) return 0;
  if(acum > k) return 0;
  if(dp[i][nb][acum] != -1) return dp[i][nb][acum];
  
  ll a1, a2;
  a1 = f(i + 1, nb, nb + acum);
  a2 = f(i + 1, nb + 1, acum);
  return dp[i][nb][acum] = a1 + a2;
}

string search(int i, int nb, int acum, ll &s, string ans, ll tot){
  if(i + 1 == n){
    ll left = tot;
    if(acum + nb == k) left++;
    
    if(s <= left) return (ans + "A");
    else return (ans + "B");
  }
  
  if(s <= dp[i + 1][nb][acum + nb] + tot) return search(i + 1, nb, nb + acum, s, ans + "A", tot);
  else return search(i + 1, nb + 1, acum, s, ans + "B", tot + dp[i + 1][nb][acum + nb]);
}

int main(){
  cin >> n >> k;
  
  FOR(i, 0, n){
    FOR(j, 0, n){
      FOR(l, 0, MAX) dp[i][j][l] = -1;
    }
  }
  
  ll tot = f(0, 0, 0), med1, med2;
  
  //cout << tot << "\n";
  
  if(tot%2){
    med1 = tot/2 + 1;
    cout << search(0, 0, 0, med1, "", 0) << "\n";
  }else{
    med1 = tot/2;
    med2 = tot/2 + 1;
    cout << search(0, 0, 0, med1, "", 0) << "\n";
    cout << search(0, 0, 0, med2, "", 0) << "\n";
  }
  
  return 0;
}