#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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
 
const ld EPSILON = 0.0000001;

struct pt{
  int x, y;

  pt(){}
  pt(int x, int y) : x(x), y(y) {}

  ld angle(const pt &p){
    ld xd = x - p.x;
    ld yd = y - p.y;
    return (180.0*fabs(atan(yd/xd)))/PI;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(7);

  int n; cin >> n;
  int x, y;
  vector<pt> pts(n);
  FOR(i, 0, n){
    cin >> x >> y;
    pts[i] = pt(x, y);
  }

  pt ori = pts[0], fin = pts[n - 1];
  ld ans1 = 0.0, ans2 = 0.0, val;
  FOR(i, 0, n){
    val = pts[i].angle(ori);
    if(val > ans1) ans1 = val;

    val = pts[i].angle(fin);
    if(val > ans2) ans2 = val;
  }

  cout << fixed << (ans1 > ans2 ? ans1 : ans2) << "\n";

  return 0;
}