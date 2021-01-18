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
#define tri pair<int, pair<int, int> >

using namespace std;

int n;
vector<int> imp;

int f(int i, int c1, int c2, deque<int> &q, map<tri, int> &dp){
  if(i == n) return 0;
  tri act = MP(i, MP(c1, c2));
  auto x = dp.find(act);
  if(x != dp.end()) return x->s;
  
  int maxi = 0, a = q[i];
  if(c1 >= a) maxi = max(maxi, 1 + f(i + 1, c1 - a, c2, q, dp));
  if(c2 >= a) maxi = max(maxi, 1 + f(i + 1, c1, c2 - a, q, dp));
  
  dp.insert(MP(act, maxi));
  return maxi;
}

void sol(int i, int c1, int c2, deque<int> &q, map<tri, int> &dp){
  if(i + 1 == n){
    int l = q[i];
    if(c1 >= l) imp[i] = 1;
    else if(c2 >= l) imp[i] = 2;
    
    return;
  }
  
  int a, b, l = q[i], ans = dp[MP(i, MP(c1, c2))];
  tri nx1 = MP(i + 1, MP(c1 - l, c2));
  tri nx2 = MP(i + 1, MP(c1, c2 - l));
  a = (c1 >= l) ? dp[nx1] + 1 : -1;
  b = (c2 >= l) ? dp[nx2] + 1 : -1;
  
  if(ans == a){
    imp[i] = 1;
    sol(i + 1, c1 - l, c2, q, dp);
  }else if(ans == b){
    imp[i] = 2;
    sol(i + 1, c1, c2 - l, q, dp);
  }
  
  return;
}

int main(){
  int cases, d, c;
  cin >> cases;
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    cin >> c;
    c *= 100;
    map<tri, int> dp;
    deque<int> q;
    
    while(cin >> d, d) q.PB(d);
    
    n = q.size();
    imp.assign(n, 0);
    cout << f(0, c, c, q, dp) << "\n";
    sol(0, c, c, q, dp);
    
    FOR(i, 0, n){
      if(imp[i] == 1) cout << "port\n";
      else if(imp[i] == 2) cout << "starboard\n";
    }
  }
  
  return 0;
}