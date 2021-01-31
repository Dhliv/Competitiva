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

bool able;

ld com(int a, int b){
  __int128 res1 = 1, res2 = 1;
  
  if(a >= b){
    FOR(i, a - b + 1, a + 1) res1 *= i;
    FOR(i, 2, b + 1) res2 *= i;
  }else able = true;
  
  return (res1*1.0)/(res2*1.0);
}

int main(){
  int a, b, c, n, k, N, cases;
  cin >> cases;
  ld c1, c2, c3, ans;
  cout.precision(4);
  
  FOR(i, 0, cases){
    cin >> a >> b >> c >> n >> k;
    N = a + b + c;
    ans = 0.0;
    able = false;
    c3 = com(N, n);
    
    FOR(j, k, n + 1){
      c1 = com(a, j);
      c2 = com(N - a, n - j);
      ans += c1*c2/c3;
    }
    
    if(able) cout << "1.0000\n";
    else cout << fixed << ans << "\n";
  }
  
  return 0;
}