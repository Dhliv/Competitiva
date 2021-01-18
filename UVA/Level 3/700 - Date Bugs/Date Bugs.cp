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
#define tri pair<int, pair<int, int> >

using namespace std;

int main(){
  int n, y, a, b, maxi, cont = 1, t;
  bool poss;
  
  while(cin >> n, n){
    cout << "Case #" << cont++ << ":\n";
    vector<pair<int, pair<int, int> > > dt(n);
    vector<int> mods(n);
    maxi = 0;
    
    FOR(i, 0, n){
      cin >> y >> a >> b;
      dt[i] = MP(y, MP(a, b));
      mods[i] = b - a;
      maxi = max(maxi, a);
    }
    
    poss = false;
    t = maxi;
    while(t < 10000){
      y = 1;
      FOR(i, 0, n) y = y and ((dt[i].s.f + (t - dt[i].s.f)%mods[i]) == dt[i].f);
      
      if(y){
        poss = true;
        cout << "The actual year is " << t << ".\n\n";
        break;
      }
      
      t++;
    }
    
    if(!poss) cout << "Unknown bugs detected.\n\n";
  }
  
  return 0;
}