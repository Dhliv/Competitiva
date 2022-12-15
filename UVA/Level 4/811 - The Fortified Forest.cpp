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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

struct pt {
  ld x, y;
  int wood, val;
};

struct res{
  int val, elements, n;
  ld wood;
  bool able;

  res(int val, int elements, ld wood, bool able, int n): val(val), elements(elements), wood(wood), able(able), n(n) {}
  res(){}
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

bool comp(const pt &a, const pt &b){
  if(fabs(a.x - b.x) < EPSILON) return a.y < b.y;
  return a.x < b.x;
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
  if (a.size() == 1)
    return;

  sort(a.begin(), a.end(), comp);
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

ld polygonPerimeter(vector<pt> &p){
  ld ans = 0, x, y;

  FOR(i, 0, p.size()){
    x = p[i].x - p[(i + 1)%p.size()].x;
    y = p[i].y - p[(i + 1)%p.size()].y;
    ans += sqrt(x*x + y*y);
  }

  return ans;
}

int n;
vector<pt> pts;

res getAns(int x){
  vector<pt> ptsaux;
  int val = 0, ele = 0;
  ld wood = 0, peri;

  FOR(i, 0, n){
    if(x & (1 << i)){
      val += pts[i].val;
      wood += pts[i].wood;
      ele++;
    }
    else{
      ptsaux.PB(pts[i]);
    }
  }

  //cout << x << " " << ele << " " << val << " :";

  convex_hull(ptsaux);
  peri = polygonPerimeter(ptsaux);
  //cout << peri << " con " << wood << "\n";
  if(peri <= wood) return res(val, ele, wood - peri, true, x);
  return res(0, 0, 0, false, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(2);

  int id = 0;
  while(cin >> n, n){
    if(id++) cout << "\n";
    cout << "Forest " << id << "\n";
    pts.assign(n, {});
    FOR(i, 0, n) cin >> pts[i].x >> pts[i].y >> pts[i].val >> pts[i].wood;

    res ans(INF, INF, INF, false, 0), aux;
    FOR(i, 1, (1 << n) - 1){
      aux = getAns(i);
      if(!aux.able) continue;

      if(aux.val <= ans.val){
        if(aux.val < ans.val) ans = aux;
        else if(aux.elements < ans.elements) ans = aux;
      }
    }

    cout << "Cut these trees:";
    FOR(i, 0, n){
      if(ans.n & (1 << i)) cout << " " << i + 1;
    }
    cout << "\nExtra wood: " << fixed << ans.wood << "\n";
  }

  return 0;
}