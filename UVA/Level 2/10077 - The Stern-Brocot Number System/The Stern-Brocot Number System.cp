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

struct frac{
  int a, b;
  
  void operator() (int c, int d){
    a = c;
    b = d;
  }
};

int main(){
  int ap, bp, ax, bx;
  frac l, r, cen;
  ld act, n, u = 1.0;
  string ans;
  
  while(cin >> ap >> bp){
    if(ap == bp and bp == 1) break;
    act = (u*ap)/(u*bp);
    ans = "";
    l(0, 1), r(1, 0), cen(1, 1);
    
    while(ap != cen.a or bp != cen.b){
      n = (u*cen.a)/(u*cen.b);
      if(act > n){
        l = cen;
        cen(l.a + r.a, l.b + r.b);
        ans += "R";
      }else{
        r = cen;
        cen(l.a + r.a, l.b + r.b);
        ans += "L";
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}