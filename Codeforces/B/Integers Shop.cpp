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

  int t, n, l, r, c, bl, br, sc, nc;
  bool ss;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    cin >> l >> r >> c;
    cout << c << "\n";
    bl = l;
    br = r;
    sc = c;

    map<int, pair<int, int>> ls, rs;
    ls.insert(MP(l, MP(c, 0)));
    rs.insert(MP(r, MP(c, 0)));

    FOR(i, 1, n){
      cin >> l >> r >> c;

      auto ax = ls.find(l);
      if(ax != ls.end()){
        if(ax->s.f > c) ls[l] = MP(c, i);
      }else ls.insert(MP(l, MP(c, i)));

      ax = rs.find(r);
      if(ax != rs.end()){
        if(ax->s.f > c) rs[r] = MP(c, i);
      }else rs.insert(MP(r, MP(c, i)));

      auto x = ls.begin();
      auto y = (--rs.end());

      nc = (x->s.s == y->s.s) ? y->s.f : x->s.f + y->s.f;

      if(x->f == l and y->f == r and nc > c){
        if(l == bl and r == br and nc > sc) nc = sc;
        bl = l;
        br = r;
        if(nc > c) nc = c;
      }else if(x->f == bl and y->f == br){
        if(sc < nc) nc = sc;
      }else{
        bl = x->f;
        br = y->f;
      }

      sc = nc;

      cout << sc << "\n";
    }
  }

  return 0;
}
