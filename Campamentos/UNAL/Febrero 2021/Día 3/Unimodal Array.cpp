#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, x;
  bool able = true;
  cin >> n;
  vector<int> q(n), p(n);
  FOR(i, 0, n) cin >> q[i];
  p[0] = 1;
  
  FOR(i, 1, n){
    x = q[i] - q[i - 1];
    p[i] = (x > 0) ? 1 : (x == 0) ? 0 : -1;
  }
  
  x = p[0];
  FOR(i, 1, n){
    if(x != p[i]){
      if(x == 1) x = p[i];
      else if(x == 0 and p[i] == -1) x = p[i];
      else{
        able = false;
        break;
      }
    }
  }
  
  if(able) cout << "YES\n";
  else cout << "NO\n";
  
  return 0;
}