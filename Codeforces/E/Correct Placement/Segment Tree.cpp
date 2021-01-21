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

struct st{
  int l, r, m;
  pair<int, int> d;
  st *left, *right;
  
  pair<int, int> com(pair<int, int> a, pair<int, int> b){
    if(a.f > b.f) return b;
    return a;
  }
  
  st(int l, int r, vector<pair<int, pair<int, int> > > &s){
    this->l = l;
    this->r = r;
    
    if(l == r) d = MP(s[l].s.f, l);
    else{
      m = (l + r)/2;
      left = new st(l, m, s);
      right = new st(m + 1, r, s);
      d = com(MP(left->d.f, left->d.s), MP(right->d.f, right->d.s));
    }
  }
  
  pair<int, int> get(int &i, int &j){
    if(i > r or j < l) return MP(INF, INF);
    if(i <= l and r <= j) return d;
    return com(left->get(i, j), right->get(i, j));
  }
};

int k;

int look(int x, vector<pair<int, pair<int, int> > > &s){
  int l = 0, r = k, m;
  
  while(l <= r){
    m = (l + r)/2;
    
    if(x <= s[m].f) r = m - 1;
    else l = m + 1;
  }
  
  return r;
}

int main(){
  int t, n, x, y, in, id, cero = 0;
  pair<int, int> m;
  vector<int> ax(1);
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    vector<int> ans(n, -1);
    vector<pair<int, pair<int, int> > > s(n);
    vector<pair<int, int> > p(n);
    
    FOR(i, 0, n){
      cin >> x >> y;
      if(x > y) swap(x, y);
      p[i] = MP(x, y);
      s[i] = MP(x, MP(y, i));
    }
    
    k = n - 1;
    sort(s.begin(), s.end());
    st tr(0, n - 1, s);
    
    FOR(i, 0, n){
      x = look(p[i].f, s);
      if(x != -1){
        m = tr.get(cero, x);
        if(m.f < p[i].s) ans[i] = s[m.s].s.s + 1;
      }
      
      x = look(p[i].s, s);
      if(x != -1){
        m = tr.get(cero, x);
        if(m.f < p[i].f) ans[i] = s[m.s].s.s + 1;
      }
    }
    
    FOR(i, 0, n) cout << ans[i] << " ";
    cout << "\n";
  }
  
  return 0;
}