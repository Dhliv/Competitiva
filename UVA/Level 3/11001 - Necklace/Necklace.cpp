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

int main(){
  int vt, v0, n1, n2;
  double x1, x2, e = 1e-6;
  
  while(cin >> vt >> v0, vt + v0){
    n2 = INF;
    n1 = vt/(2*v0);
    if(vt%(2*v0) != 0) n2 = n1 + 1;
    
    if(vt > v0){
      if(n2 == INF) cout << n1 << "\n";
      else{
        x1 = n1*0.3*sqrt(vt/(1.0*n1) - v0*1.0);
        x2 = n2*0.3*sqrt(vt/(1.0*n2) - v0*1.0);
        if(fabs(x1 - x2) < e) cout << "0\n";
        else{
          if(x1 > x2) cout << n1 << "\n";
          else cout << n2 << "\n";
        }
      }
    }else cout << "0\n";
  }
  
  return 0;
}