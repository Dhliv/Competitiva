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

bool point_in_segment(pt P, pt a, pt b){
  ld maxix, minix, maxiy, miniy;
  maxix = max(a.x, b.x);
  minix = min(a.x, b.x);
  maxiy = max(a.y, b.y);
  miniy = min(a.y, b.y);

  ld A, B, C;
  A = -(a.y - b.y);
  B = a.x - b.x;
  C = -(B*b.y - A*b.x);
  ld res = A*P.x + B*P.y + C;

  if(fabs(res) < EPSILON and P.x + EPSILON >= minix and P.x - EPSILON <= maxix and P.y + EPSILON >= miniy and P.y - EPSILON <= maxiy) return true;
  return false;
}

bool lines_intersect(pt a, pt b, pt c, pt d){
  int o1, o2, o3, o4;
  o1 = orientation(a, b, c);
  o2 = orientation(a, b, d);
  o3 = orientation(c, d, a);
  o4 = orientation(c, d, b);

  if(o1 != o2 and o3 != o4) return true;

  if(o1 == 0 and point_in_segment(c, a, b)) return true;
  if(o2 == 0 and point_in_segment(d, a, b)) return true;
  if(o3 == 0 and point_in_segment(a, c, d)) return true;
  if(o4 == 0 and point_in_segment(b, c, d)) return true;

  return false;
}

// 'a' and 'b' forms the line of some side of convex hull.
pt calc_intersection(pt a, pt b, pt c, pt d){
  ld A1, A2, B1, B2, C1, C2;
  pt ans;

  if(point_in_segment(a, c, d)) return a;
  if(point_in_segment(b, c, d)) return b;
  if(point_in_segment(c, a, b)) return c;
  if(point_in_segment(d, a, b)) return d;

  A1 = -(a.y - b.y);
  B1 = a.x - b.x;
  C1 = -B1*b.y - A1*b.x;

  A2 = -(c.y - d.y);
  B2 = c.x - d.x;
  C2 = -B2*d.y - A2*d.x;

  ans.x = (C1*B2 - C2*B1)/(A2*B1 - A1*B2);
  if(fabs(a.y - b.y) < EPSILON){
    ans.y = a.y;
  }else ans.y = -(C1 + A1*ans.x)/B1;

  return ans;
}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
  if (a.size() == 1)
    return;

  sort(a.begin(), a.end(), [](pt a, pt b) {
    if(fabs(a.x - b.x) < EPSILON) return a.y > b.y;
    return a.x < b.x;
  });
  pt p1 = a[0], p2 = a.back();
  vector<pt> up;
  up.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
      while (up.size() >= 2){
        if(cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear)) break;
        up.pop_back();
      }
      up.push_back(a[i]);
    }
  }

  if (include_collinear && up.size() == a.size()) {
    reverse(a.begin(), a.end());
    return;
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(8);

  pt goal, ans, ori, comparator;
  int n; cin >> n;
  cin >> goal.x >> goal.y;

  comparator.x = goal.x*((ld) 1000000.0);
  comparator.y = goal.y*((ld) 1000000.0);

  ld maxix = 0.0, maxiy = 0.0;

  vector<pt> pts(n + 2);
  FOR(i, 0, n){
    cin >> pts[i].x >> pts[i].y;
    maxix = max(maxix, pts[i].x);
    maxiy = max(maxiy, pts[i].y);
  }

  pts[n].x = maxix;
  pts[n + 1].y = maxiy;

  convex_hull(pts, false);

  //FOR(i, 0, pts.size()) cout << pts[i].x << " " << pts[i].y << "\n";

  FOR(i, 0, pts.size() - 1){
    if(lines_intersect(pts[i], pts[i + 1], ori, comparator)){
      ans = calc_intersection(pts[i], pts[i + 1], ori, comparator);
      cout << fixed << goal.x/ans.x << "\n";
      break;
    }
  }

  return 0;
}