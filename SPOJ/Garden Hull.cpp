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

const ld EPSILON = 0.0000001;

struct pt {
  ld x, y;

  pt(){
    x = y = 0.0;
  }

  void print(){
    cout << x << " " << y << "\n";
  }
};

int orientation(pt a, pt b, pt c) {
  ld v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  if (v < 0) return -1; // clockwise
  if (v > 0) return +1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
  if (a.size() == 1)
    return;

  sort(a.begin(), a.end(), [](pt a, pt b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
  });
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
      while (up.size() >= 2){
        if(cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear)) break;
        up.pop_back();
      }
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
      while (down.size() >= 2){
        if(ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear)) break;
        down.pop_back();
      }
      down.push_back(a[i]);
    }
  }

  if (include_collinear && up.size() == a.size()) {
    reverse(a.begin(), a.end());
    return;
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--)
    a.push_back(down[i]);
}

ld norm(pt &a, pt &b){
  ld x, y;
  x = a.x - b.x;
  y = a.y - b.y;

  return sqrt(x*x + y*y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<pt> pts(n);

  FOR(i, 0, n) cin >> pts[i].x >> pts[i].y;

  convex_hull(pts, false);

  ld ans = 0.0;
  FOR(i, 0, pts.size()){
    ans += norm(pts[i], pts[(i + 1)%pts.size()]);
  }

  cout << round(ans) << "\n";

  return 0;
}