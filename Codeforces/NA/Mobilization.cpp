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
#define ld long double

using namespace std;

const ld EPSILON = 1e-9;

struct pt {
    ld x, y;
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

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up;
    up.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
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

ld f(pt &a, pt &b, ld x, ld maxi){
  ld h, p;
  h = a.x*x + b.x*(maxi - x);
  p = a.y*x + b.y*(maxi - x);

  return h*p;
}

ld ternary_search(ld l, ld r, pt &a, pt &b) {
    const ld MAXI = r;
    ld m1, m2, f1, f2;
    while (r - l > EPSILON) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        f1 = f(a, b, m1, MAXI);
        f2 = f(a, b, m2, MAXI);
        if (f1 < f2) l = m1;
        else r = m2;
    }

    return f(a, b, l, MAXI);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(2);

  int n;
  ld C, h, p, c;

  cin >> n >> C;
  vector<pt> ps(n);
  FOR(i, 0, n){
    cin >> c >> h >> p;
    ps[i] = {h/c, p/c};
  }

  convex_hull(ps, true);

  ld ans = 0.0, ax;
  FOR(i, 0, ps.size() - 1){
    ax = ternary_search(0.0, C, ps[i], ps[i + 1]);
    if(ax > ans) ans = ax;
  }

  cout << fixed << ans << "\n";

  return 0;
}