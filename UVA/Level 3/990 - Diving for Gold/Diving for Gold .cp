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

int n, t, w;
int dp[30][1001], imp[30];

int f(int i , int s, deque<pair<int, int> > &q){
  if(i == n or s == 0) return 0;
  int &ans = dp[i][s];
  if(ans != -1) return ans;
  
  int maxi = 0, tg = 3*w*q[i].f, g = q[i].s;
  maxi = f(i + 1, s, q);
  if(s >= tg) maxi = max(maxi, g + f(i + 1, s - tg, q));
  
  return ans = maxi;
}

int sol(int i, int s, deque<pair<int, int> > &q){
  int tg = 3*w*q[i].f;
  if(i + 1 == n){
    if(s >= tg){
      imp[i] = 1;
      return 1;
    }else return 0;
  }
  
  if(s >= tg){
    if(dp[i][s] > dp[i + 1][s]){
      imp[i] = 1;
      return 1 + sol(i + 1, s - tg, q);
    }else return sol(i + 1, s, q);
  }else return sol(i + 1, s, q);
}

int main(){
  int d, g, cont = 0, te;
  
  while(cin >> t >> w){
    if(cont++) cout << "\n";
    cin >> n;
    deque<pair<int, int> > q(n);
    
    FOR(i, 0, n){
      cin >> d >> g;
      q[i] = MP(d, g);
    }
    
    memset(dp, -1, sizeof(dp));
    memset(imp, 0, sizeof(imp));
    cout << f(0, t, q) << "\n";
    te = sol(0, t, q);
    
    cout << te << "\n";
    FOR(i, 0, n) if(imp[i]) cout << q[i].f << " " << q[i].s << "\n";
  }
  
  return 0;
}