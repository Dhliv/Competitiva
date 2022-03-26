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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("citystate.in");
  ofstream cout("citystate.out");

  ll ans = 0;
  map<pair<string, string>, ll> c;
  int n; cin >> n;
  string city, state;

  FOR(i, 0, n) {
    cin >> city >> state;
    city = city.substr(0, 2);

    if(city == state) continue;

    auto it = c.find(MP(city, state));
    if(it != c.end()) it->s++;
    else c.insert(MP(MP(city, state), 1));
  }

  set<pair<string, string> > era;
  for(auto cs: c) {
    auto er = era.find(cs.f);
    if(er != era.end()) continue;

    auto it = c.find(MP(cs.f.s, cs.f.f));
    if(it != c.end()){
      era.insert(cs.f);
      era.insert(MP(cs.f.s, cs.f.f));
      ans += cs.s*it->s;
    }
  }

  cout << ans << "\n";

  return 0;
}
