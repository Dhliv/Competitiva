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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

bool distance(pair<int, int> a, pair<int, int> b, int r){
  ld d = sqrt(pow((a.f - b.f), 2) + pow((a.s - b.s), 2));
  
  if(fabs(d - r) < 1e-7) return true;
  else if(d <= r) return true;
  else return false;
}

int main(){
  int x1, x2, y1, y2, maxy, miny, maxx, minx, n, x, y, r;
  cin >> x1 >> y1 >> x2 >> y2;
  
  maxy = max(y1, y2);
  miny = min(y1, y2);
  maxx = max(x1, x2);
  minx = min(x1, x2);
  
  map<pair<int, int>, int> rad;
  vector<pair<int, int> > gen;
  
  FOR(i, minx, maxx + 1){
    gen.PB(MP(i, miny));
    gen.PB(MP(i, maxy));
  }
  
  FOR(i, miny + 1, maxy){
    gen.PB(MP(minx, i));
    gen.PB(MP(maxx, i));
  }
  
  cin >> n;
  
  FOR(i, 0, n){
    cin >> x >> y >> r;
    if(rad.find(MP(x, y)) == rad.end()) rad.insert(MP(MP(x, y), r));
    else rad[MP(x, y)] = max(rad[MP(x, y)], r);
  }
  
  int ans = 0;
  bool able;
  
  FOR(i, 0, gen.size()){
    able = false;
    forit(x, rad){
      if(distance(gen[i], x->f, x->s)){
        able = true;
        break;
      }
    }
    
    if(!able) ans++;
  }
  
  cout << ans << "\n";
  
  return 0;
}