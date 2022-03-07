#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

struct rect{
  ll x1, x2, y1, y2;

  ll area(){
    return (y2 - y1)*(x2 - x1);
  }
};

ll mini(ll &a, ll &b){
  return (a > b ? b : a);
}

ll maxi(ll a, ll b){
  return (a > b ? a : b);
}

ll inter(rect &a, rect &b){
  ll x = maxi(0, mini(a.x2, b.x2) - maxi(a.x1, b.x1));
  ll y = maxi(0, mini(a.y2, b.y2) - maxi(a.y1, b.y1));

  return x*y;
}

pair<bool, rect> rectInter(rect &a, rect &b){
  rect c;
  c.x1 = maxi(a.x1, b.x1);
  c.x2 = mini(a.x2, b.x2);
  c.y1 = maxi(a.y1, b.y1);
  c.y2 = mini(a.y2, b.y2);
  ll x = maxi(0, c.x2 - c.x1);
  ll y = maxi(0, c.y2 - c.y1);

  return MP(x*y > 0, c);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  rect wh, b1, b2, posIB;
  cin >> wh.x1 >> wh.y1 >> wh.x2 >> wh.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  auto b1b2 = rectInter(b1, b2);

  if((wh.area() - inter(wh, b1) - inter(wh, b2) + (b1b2.f ? inter(wh, b1b2.s) : 0)) > 0) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
