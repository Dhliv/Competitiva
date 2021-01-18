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
#define est pair<int, pair<int, pair<int, int> > >

using namespace std;

map<est, int> dp;

int f(int i, int h, int s, int e, deque<int> &q){
  if(i == q.size()) return s;
  est act = MP(i, MP(h, MP(s, e)));
  if(dp.find(act) != dp.end()) return dp[act];
  
  int maxi;
  maxi = f(i + 1, h, s, e, q);
  
  if(e){
    if(h >= q[i]) maxi = max(maxi, f(i + 1, q[i], s + 1, e, q));
  }else maxi = max(maxi, f(i + 1, q[i], s + 1, 1, q));
  
  dp.insert(MP(act, maxi));
  return maxi;
}

int main(){
  int a, cont = 0;
  
  while(cin >> a, a != -1){
    if(cont++) cout << "\n";
    
    deque<int> q;
    q.PB(a);
    
    while(cin >> a, a != -1) q.PB(a);
    
    cout << "Test #" << cont << ":\n  ";
    cout << "maximum possible interceptions: " << f(0, 0, 0, 0, q) << "\n";
    
    dp.clear();
  }
  
  return 0;
}