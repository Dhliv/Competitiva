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
#define coor pair<int, pair<int, int> >
#define est pair<int, pair<int, int> >

using namespace std;

int f(int i, int a, int b, deque<coor> &q, map<est, int> &dp){
  if(i == q.size()) return 0;
  est act = MP(i, MP(a, b));
  if(dp.find(act) != dp.end()) return dp[act];
  
  int maxi, na = q[i].f, nb = q[i].s.f, h = q[i].s.s;
  maxi = f(i + 1, a, b, q, dp);
  
  if(a < na and b < nb) maxi = max(maxi, h + f(i + 1, na, nb, q, dp));
  
  dp.insert(MP(act, maxi));
  return maxi;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d[3], cont = 1;
  
  while(cin >> n, n){
    deque<coor> q;
    set<coor> all;
    map<est, int> dp;
    
    FOR(i, 0, n){
      cin >> d[0] >> d[1] >> d[2];
      
      FOR(j, 0, 3){
        FOR(k, 0, 3){
          if(j == k) continue;
          FOR(l, 0, 3){
            if(l == k or l == j) continue;
            all.insert(MP(d[j], MP(d[k], d[l])));
          }
        }
      }
    }
    
    for(auto x: all) q.PB(MP(x.f, MP(x.s.f, x.s.s)));
    
    cout << "Case " << cont++ << ": maximum height = " << f(0, 0, 0, q, dp) << "\n";
  }
  
  return 0;
}