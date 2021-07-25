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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, xi, yi, xo, yo, xf, yf, ans;
  cin >> t;

  FOR(ab, 0, t){
    cin >> xi >> yi >> xo >> yo >> xf >> yf;
    ans = (abs(xo - xi) + abs(yo - yi));
    if(xi == xo and xf == xi and yf >= min(yi, yo) and yf <= max(yi, yo)) ans += 2;
    if(yo == yi and yf == yi and xf >= min(xi, xo) and xf <= max(xi, xo)) ans += 2;
    cout << ans << "\n";
  }

  return 0;
}