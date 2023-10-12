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

struct pt {
  ld x, y;

  void print(){
  	cout << x << " " << y << "\n";
  }
};

struct line {
    ld a, b, c;
};

const ld EPS = 1e-9;

ld det(ld a, ld b, ld c, ld d) {
    return a*d - b*c;
}

bool intersect(line m, line n, pt & res) {
    ld zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

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

pt getAdditionalPoint(pt A, pt B, pt P){
	if(abs(A.x - B.x) < EPS) return pt{P.x + 10, P.y};
	if(abs(A.y - B.y) < EPS) return pt{P.x, P.y + 10};

	ld m = (A.y - B.y)/(A.x - B.x);
	pt neoPoint;
	neoPoint.x = P.x + 1;
	neoPoint.y = P.y + m*(neoPoint.x - P.x);
	return neoPoint;
}

line transformLine(pt a, pt b){
	ld A, B, C;

	A = a.y - b.y;
	B = b.x - a.x;
	C = a.x*b.y - b.x*a.y;

	return line{A, B, C};
}

ld area(const vector<pt>& fig) {
    ld res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

ld vectorNorm(pt x, pt y){
	ld X, Y;
	X = x.x - y.x;
	Y = x.y - y.y;
	return sqrt(X*X + Y*Y);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	ld x0, yO, xf, yf, n;
	ld dos = 2;

	while(t--){
		cin >> x0 >> yO >> xf >> yf >> n;
		vector<pt> grif(n), sly(n), all(2*n);

		FOR(i, 0, n){
			cin >> grif[i].x >> grif[i].y;
			all[i] = grif[i];
		}

		FOR(i, 0, n){
			cin >> sly[i].x >> sly[i].y;
			all[i + n] = sly[i];
		}

		vector<line> lines;
		vector<pt> pts;
		FOR(i, 0, 2*n){
			FOR(j, i + 1, 2*n){
				pt P{(all[i].x + all[j].x)/dos, (all[i].y + all[j].y)/dos};
				pts.PB(P);
				pt Q = getAdditionalPoint(all[i], all[j], P);
				lines.PB(transformLine(P, Q));
			}
		}

		lines.PB(transformLine(pt{x0, yO}, pt{x0, yf}));
		lines.PB(transformLine(pt{x0, yO}, pt{xf, yO}));
		lines.PB(transformLine(pt{x0, yf}, pt{xf, yf}));
		lines.PB(transformLine(pt{xf, yO}, pt{xf, yf}));

		pt intersection;
		FOR(i, 0, lines.size()){
			FOR(j, i + 1, lines.size()){
				bool able = intersect(lines[i], lines[j], intersection);
				if(able) pts.PB(intersection);
			}
		}

		pts.PB(pt{x0, yO});
		pts.PB(pt{x0, yf});
		pts.PB(pt{xf, yO});
		pts.PB(pt{xf, yf});

		//FOR(i, 0, pts.size()) pts[i].print();

		vector<ld> dp(pts.size(), INF);

		FOR(i, 0, pts.size()){
			FOR(j, 0, all.size()){
				ld dist = vectorNorm(pts[i], all[j]);
				if(abs(dist - dp[i]) < EPS) continue;
				if(dist < dp[i]) dp[i] = dist;
			}
		}

		ld areaG = 0.0, areaS = 0.0;

		FOR(i, 0, n){

			vector<pt> hull, hull2;
			hull.PB(grif[i]);
			hull2.PB(sly[i]);
			FOR(j, 0, pts.size()){
				if(abs(dp[j] - vectorNorm(pts[j], grif[i])) < EPS) hull.PB(pts[j]);
				if(abs(dp[j] - vectorNorm(pts[j], sly[i])) < EPS) hull2.PB(pts[j]);
			}

			convex_hull(hull, true);
			convex_hull(hull2, true);
			areaG += area(hull);
			areaS += area(hull2);
		}

		if(areaG > areaS) cout << "Gryffindor\n";
		else cout << "Slytherin\n";
	}
	
	return 0;
}