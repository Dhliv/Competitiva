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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

typedef pair<double, double> pdd;

bool check(double x, double y, double w, double z, pdd p){
  if(x < p.f and p.f < w){
    if(z < p.s and p.s < y) return true;
  }
  
  return false;
}

int main(){
  int cont = 1;
  double x, y, w, z;
  vector<pair<pdd, pdd> > r;
  string ent;
  bool pos, ins;
  
  while(cin >> ent, ent != "*"){
    cin >> x >> y >> w >> z;
    r.PB(MP(MP(x, y), MP(w, z)));
  }
  
  while(cin >> x >> y, x + y != 19999.8){
    ins = false;
    FOR(i, 0, r.size()){
      pos = check(r[i].f.f, r[i].f.s, r[i].s.f, r[i].s.s, MP(x, y));
      if(pos){
        cout << "Point " << cont << " is contained in figure " << i + 1 << "\n";
        ins = true;
      }
    }
    if(!ins) cout << "Point " << cont << " is not contained in any figure\n";
    cont++;
  }
  
  return 0;
}
