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

int vd, vp, t, f, c;

double col(double xp){
  double ti = xp/((vd - vp)*1.0);
  return ti;
}

int main(){
  int ans = 0;
  double xp, t1, tf;
  cin >> vp >> vd >> t >> f >> c;
  
  if(vd <= vp)
    cout << ans << "\n";
  else{
    xp = vp*t;
    t1 = col(1.0*xp);
    xp += t1*vp*1.0;
    while(xp < c*1.0){
      ans++;
      xp += (t1*1.0 + f*1.0)*vp*1.0;
      t1 = col(1.0*xp);
      xp += t1*vp*1.0;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}