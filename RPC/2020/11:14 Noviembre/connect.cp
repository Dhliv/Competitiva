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
  int n, m, x, y, fx, fy, c;
  ll ans, g;
  
  cin >> n >> m;
  vector<int> p(n + 1);
  vector<ll> sum(n + 1, 1);
  
  FOR(i, 1, n + 1) p[i] = i;
  ans = g = n;
  
  FOR(i, 0, m){
    cin >> c;
    if(c == 1){
      cin >> x >> y;
      fx = find(x, p), fy = find(y, p);
      
      if(fx != fy){
        g--;
        ans -= (sum[fx]*sum[fx] + sum[fy]*sum[fy]);
        p[fx] = fy;
        sum[fy] += sum[fx];
        ans += sum[fy]*sum[fy];
      }
    }else{
      x = __gcd(g, ans);
      cout << ans/x << "/" << g/x << "\n";
    }
  }
  
  return 0;
}