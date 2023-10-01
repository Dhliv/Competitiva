#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
#define EPS 0.000000001

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(8);

  ld x, y, r;
  cin >> y >> x >> r;
  ld A, B, C;
  A = 1 + (y*y)/(x*x);
  B = -2*((y*y)/x);
  C = y*y - r*r;
  ld disc = B*B - 4*A*C;
  const ld ANGLE = 180.0;

  if(fabs(disc) <= EPS){
    ld x1 = -B/(2*A);
    ld y1 = y - (y/x)*x1;
    ld t1 = fabs(atan(y1/x1)*ANGLE/PI);
    cout << fixed << t1 << "\n";
  } else if(disc < 0.0) cout << "-1\n";
  else{
    ld x1, x2;
    x1 = (-B + sqrt(disc))/(2*A);
    x2 = (-B - sqrt(disc))/(2*A);
    ld y1, y2;
    y1 = y - (y/x)*x1;
    y2 = y - (y/x)*x2;

    ld t1, t2;
    t1 = fabs(atan(y1/x1)*ANGLE/PI);
    t2 = fabs(atan(y2/x2)*ANGLE/PI);

    if(fabs(t1 - t2) <= EPS or t1 < t2) cout << fixed << t1 << "\n";
    else cout << fixed << t2 << "\n";
  }

  return 0;
}