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

using namespace std;

struct pt{
  ld x, y;

  pt(){}
  pt(ld x, ld y) : x(x), y(y){}
};

vector<vector<pt> > segments(4);
ld halfx;

ld area(vector<pt>& fig) {
  ld res = 0;
  for (unsigned i = 0; i < fig.size(); i++) {
    pt p = i ? fig[i - 1] : fig.back();
    pt q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
  }
  return fabs(res) / 2;
}

ld f(ld height){
  ld maxi = -1.0, mini = INF, ar;
  vector<pt> fig;

  FOR(i, 0, 4){
    fig = segments[i];
    fig.PB(pt(halfx, height));
    ar = area(fig);
    if(ar > maxi) maxi = ar;
    if(ar < mini) mini = ar;
  }

  return maxi - mini;
}

ld ternary_search(ld l, ld r) {
  ld eps = 1e-9;
  ld m1, m2, f1, f2;
  while (r - l > eps) {
    m1 = l + (r - l) / 3;
    m2 = r - (r - l) / 3;
    f1 = f(m1);      //evaluates the function at m1
    f2 = f(m2);      //evaluates the function at m2
    if (f1 > f2) l = m1;
    else r = m2;
  }

  //return the maximum of f(x) in [l, r]
  return f(l);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(8);

  ld b1, b2, h; cin >> b1 >> b2 >> h;
  ld x = b2/2.0;
  halfx = b1/2.0;
  ld b5 = (b1 - b2)/2.0;

  segments[0].PB(pt(0.0, 0.0));
  segments[0].PB(pt(b1, 0.0));
  segments[1].PB(pt(b1, 0.0));
  segments[1].PB(pt(b1 - b5, h));
  segments[2].PB(pt(b1 - b5, h));
  segments[2].PB(pt(b5, h));
  segments[3].PB(pt(b5, h));
  segments[3].PB(pt(0.0, 0.0));

  cout << fixed << ternary_search(0.0, h) << "\n";

  return 0;
}