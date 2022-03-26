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

  ll k, n, x, val; cin >> k >> n;
  vector<ll> judge(k);
  map<ll, int> vals, cp;
  set<ll> ans;

  FOR(i, 0, k) cin >> judge[i];
  FOR(i, 0, n){
    cin >> x;
    vals.insert(MP(x, 1));
  }

  bool able;
  val = vals.begin()->f;
  FOR(i, 0, k){
    x = val;
    cp = vals;
    able = true;

    FOR(j, i + 1, k){
      x += judge[j];
      auto it = cp.find(x);
      if(it != cp.end()) it->s--;
    }

    x = val;
    FORI(j, i, 0){
      auto it = cp.find(x);
      if(it != cp.end()) it->s--;
      x -= judge[j];
    }

    for(auto v: cp){
      if(v.s > 0) {
        able = false;
        break;
      }
    }

    if(able) ans.insert(x);
  }

  cout << ans.size() << "\n";

  return 0;
}
