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

struct point{
  int x, y;

  point(){}

  void operator()(int x, int y){
    this->x = x;
    this->y = y;
  }
};


bool operator<(const point &a, const point &b){
  if(a.x == b.x){
    return a.y < b.y;
  }

  return a.x < b.x;
}

void add(ll n, map<ll, int> &m){
  auto it = m.find(n);
  if(it == m.end()) m.insert({n, 1});
  else it->s++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, x, y;

  while(t--){
    cin >> n;
    map<ll, int> enY, enX, menos, mas;
    ll ans = 0, sl;

    vector<point> p(n);
    FOR(i, 0, n){
      cin >> x >> y;
      p[i](x, y);
      add(x, enY);
      add(y, enX);
      add(x - y, mas);
      add(y + x, menos);
    }

    FOR(i, 0, n){
      ans += enY[p[i].x] - 1;
      ans += enX[p[i].y] - 1;
      ans += menos[p[i].y + p[i].x] - 1;
      ans += mas[p[i].x - p[i].y] - 1;
    }

    cout << ans << "\n";
  }
 
  return 0;
}