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

int find(int x, vector<int> &p){
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

int main(){
  int cases, n, m, x, y, c, fx, fy;
  bool poss;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n >> m;
    vector<int> p(n), debt(n);
    FOR(i, 0, n) p[i] = i;
    FOR(i, 0, n) cin >> debt[i];
    
    FOR(i, 0, m){
      cin >> x >> y;
      fx = find(x, p), fy = find(y, p);
      if(fx != fy){
        p[fx] = fy;
        debt[fy] += debt[fx];
      }
    }
    
    poss = true;
    FOR(i, 0, n){
      x = find(i, p);
      if(debt[x] != 0){
        poss = false;
        break;
      }
    }
    
    if(poss) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
  }
  
  return 0;
}