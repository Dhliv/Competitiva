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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll xc, yc, xu, yu, dat, a, b, c, ans = 0;
  ll l1, l2;
  cin >> xc >> yc >> xu >> yu >> dat;
  
  FOR(i, 0, dat){
    cin >> a >> b >> c;
    l1 = a*xc + b*yc + c;
    l2 = a*xu + b*yu + c;
    
    if(l1 > 0 and l2 < 0) ans++;
    else if(l1 < 0 and l2 > 0) ans++;
  }
  
  cout << ans << "\n";
  
  return 0;
}