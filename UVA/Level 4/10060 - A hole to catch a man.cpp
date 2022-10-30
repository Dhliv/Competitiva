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

struct pt{
  ld x, y;
};

ld calc_area(const vector<pt>& fig, int size) {
  ld res = 0;
  for(unsigned i = 0; i < size; i++) {
    pt p = fig[(i - 1 + size)%size];
    pt q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
  }
  return fabs(res) / 2;
}

bool operator==(pt &a, pt &b){
  if(fabs(a.x - b.x) < EPSILON and fabs(a.y - b.y) < EPSILON) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  ld x, y, t;
  vector<pt> pts(1000000);
  pt a;
  int p;

  while(cin >> n, n){
    ld area = 0.0;

    FOR(i, 0, n){
      cin >> t >> x >> y;
      pts[0] = pt{x, y};
      p = 1;

      while(true){
        cin >> a.x >> a.y;
        if(a == pts[0]) break;
        pts[p++] = a;
      }

      area += calc_area(pts, p)*t;
    }

    cin >> x >> y;

    cout << floor(area/(PI*x*x*y)) << "\n";
  }
  
  return 0;
}