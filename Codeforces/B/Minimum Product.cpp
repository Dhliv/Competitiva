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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;


int main(){
  int cases, x, y, k, n, dx, dy, aux;
  ll p, a, b, q;
  cin >> cases;
  
  FOR(c, 0, cases){
    cin >> a >> b >> x >> y >> n;
    if((a - n) >= x){
      p = b*(a - n);
    }else{
      dx = n;
      dy = x;
      dx -= (a - x);
      if((b - dx) >= y){
        p = (b - dx)*dy;
      }else{
        p = ((ll)y)*dy;
      }
    }
    
    if((b - n) >= y){
      q = a*(b - n);
    }else{
      dx = n;
      dy = y;
      dx -= (b - y);
      if((a - dx) >= x){
        q = (a - dx)*dy;
      }else{
        q = ((ll)x)*dy;
      }
    }
    
    cout << min(p, q) << "\n";
  }
  
  return 0;
}
