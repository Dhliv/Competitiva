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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, a; cin >> s;

  vector<vector<int> > p(250);
  FOR(i, 0, s.size()){
    p[s[i]].PB(i);
  }

  FOR(i, 0, 250) p[i].PB(INF);

  int q, l, x, y; cin >> q;
  bool able, fs;

  FOR(ab, 0, q){
    cin >> a;
    able = fs = true;
    l = -1;

    FOR(i, 0, a.size()){
      l = p[a[i]][upper_bound(p[a[i]].begin(), p[a[i]].end(), l) - p[a[i]].begin()];
      if(fs){
        fs = 0;
        x = l;
        y = l;
      }else y = l;

      if(l == INF){
        able = false;
        break;
      }
    }

    if(able) cout << "Matched " << x << " " << y << "\n";
    else cout << "Not matched\n";
  }

  return 0;
}