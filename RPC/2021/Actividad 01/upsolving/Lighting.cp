#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
#define ll long long
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
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, x, y, fx, fy;
  
  while(cin >> n >> m){
    vector<int> p(n + 1), sums(n + 1, 1), lo(n + 1);
    FOR(i, 1, n + 1) p[i] = i;
    
    FOR(i, 0, m){
      cin >> x >> y;
      fx = find(x, p);
      fy = find(y, p);
      if(fx != fy){
        p[fx] = fy;
        sums[fy] += sums[fx];
      }
    }
    
    FOR(i, 1, n + 1){
      fx = find(i, p);
      if(!lo[fx]){
        lo[fx] = 1;
        cout << i << " " << sums[fx] << "\n";
      }
    }
  }
  
  return 0;
}