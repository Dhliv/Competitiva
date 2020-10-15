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

ld a, b, c, d, e, f, eps = 1e-7, ace = 1e-6;

ld g(int n, ld x){
  if(n == 1) return x*a + b;
  else if(n == 2) return x*x*a + x*b + c;
  else if(n == 3) return x*x*x*a + x*x*b + x*c + d;
  else if(n == 4) return x*x*x*x*a + x*x*x*b + x*x*c + x*d + e;
  else return x*x*x*x*x*a + x*x*x*x*b + x*x*x*c + x*x*d + x*e + f;
}

ld gp(int n, ld x){
  if(n == 1) return a;
  else if(n == 2) return 2.0*x*a + b;
  else if(n == 3) return 3.0*x*x*a + 2.0*x*b + c;
  else if(n == 4) return 4.0*x*x*x*a + 3.0*x*x*b + 2.0*x*c + d;
  else return 5.0*x*x*x*x*a + 4.0*x*x*x*b + 3.0*x*x*c + 2.0*x*d + e;
}

ld newton(int n, ld xi){
  ld x = xi, nx;
  while(true){
    nx = (x - (g(n, x))/(gp(n, x)));
    if(abs(x - nx) < eps) return x;
    x = nx;
  }
}

int main(){
  int grad, cont = 1;
  ld r, bef;
  cout.precision(4);
  
  while(cin >> grad, grad){
    vector<ld> imp;
    if(grad == 1) cin >> a >> b;
    else if(grad == 2) cin >> a >> b >> c;
    else if(grad == 3) cin >> a >> b >> c >> d;
    else if(grad == 4) cin >> a >> b >> c >> d >> e;
    else cin >> a >> b >> c >> d >> e >> f;
    
    for(ld i = -25.0; i <= 25.0; i += 0.1){
      r = newton(grad, i);
      if(imp.size()){
        if(abs(r - imp[imp.size() - 1]) > ace) imp.PB(r);
      }
      else imp.PB(r);
    }
    sort(imp.begin(), imp.end());
    
    bef = imp[0];
    cout << "Equation " << cont++ << ": " << fixed << bef;
    
    FOR(i, 1, imp.size()){
      if(abs(bef - imp[i]) > ace){
        cout << " " << fixed << imp[i];
        bef = imp[i];
      }
    }
    
    cout << "\n";
  }
  
  return 0;
}