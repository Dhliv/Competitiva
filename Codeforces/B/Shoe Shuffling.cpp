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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x; cin >> t;
  vector<int> vacio(1);

  FOR(ab, 0, t){
    cin >> n;
    map<int, vector<int> > p;
    FOR(i, 0, n){
      cin >> x;

      auto it = p.find(x);
      if(it != p.end()) it->s.PB(i);
      else{
        vacio[0] = i;
        p.insert(MP(x, vacio));
      }
    }

    deque<int> ans;
    bool able = true;
    for(const auto &y: p){
      if(y.s.size() == 1){
        able = false;
        break;
      }else{
        FOR(i, 1, y.s.size()) ans.PB(y.s[i]);
        ans.PB(y.s[0]);
      }
    }

    if(!able) cout << "-1\n";
    else{
      FOR(i, 0, ans.size()) cout << ans[i] + 1 << " ";
      cout << "\n";
    }
  }

  return 0;
}