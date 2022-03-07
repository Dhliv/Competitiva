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
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("lostcow.in");
  ofstream cout("lostcow.out");

  int x, y, nx, ans, lp; cin >> x >> y;
  ans = 0;
  lp = x;

  FOR(i, 0, 12){
    nx = x + (i & 1 ? -(1 << i) : (1 << i));
    ans += abs(nx - lp);
    lp = nx;

    if(x > y){
      if(nx <= y){
        ans -= (y - nx);
        break;
      }
    }else{
      if(nx >= y){
        ans -= (nx - y);
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
