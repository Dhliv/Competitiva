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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int p, a, b, c, d, k;

ld price(int k){
  ld ans = p*1.0*(sin(k*a + b) + cos(k*c + d) + 2.0);
  return ans;
}

int main(){
  ld maxi = 1.0*MINF, dif = 0.0, epsi = 1e-7, ax;
  cout.precision(8);
  
  while(cin >> p >> a >> b >> c >> d >> k){
    maxi = 1.0*MINF;
    dif = 0.0;
    
    FOR(i, 1, k + 1){
      ax = price(i);
      if(fabs(ax - maxi) > epsi){
        if((ax - maxi) > 0.0) maxi = ax;
        else{
          if((maxi - ax) > epsi){
            if((maxi - ax - dif) > epsi){
              dif = maxi - ax;
            }
          }
        }
      }
    }
    
    cout << fixed << dif << "\n";
  }
  
  return 0;
}