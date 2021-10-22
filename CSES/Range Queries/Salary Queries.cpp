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
  int l, r, m, vecs;
  st *left, *right;

  st(int l, int r){
    this->l = l;
    this->r = r;

    vecs = 0;

    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
  }

  void up(int &x, const int &val){
    if(l == r){
      vecs += val;
      return;
    }

    if(x <= m) left->up(x, val);
    else right->up(x, val);
    vecs += val;

    return;
  }

  int get(int &i, int &j){
    if(r < i or l > j) return 0;
    if(i <= l and r <= j) return vecs;
    return (left->get(i, j) + right->get(i, j));
  }
};
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q, x, y;
  const int sum = 1, res = -1;
  char k;
  cin >> n >> q;
  deque<int> ord, ids, p(n);
  deque<pair<char, pair<int, int> > > qrs(q);

  FOR(i, 0, n){
    cin >> p[i];
    ord.PB(p[i]);
  }

  FOR(i, 0, q){
    cin >> k >> x >> y;
    qrs[i] = MP(k, MP(x, y));
    if(k == '?') ord.PB(x);
    ord.PB(y);
  }

  sort(ord.begin(), ord.end());

  ids.PB(ord[0]);
  x = ord[0];

  FOR(i, 1, ord.size()){
    if(ord[i] != x){
      x = ord[i];
      ids.PB(x);
    }
  }

  st tr(0, ids.size() - 1);

  FOR(i, 0, n){
    x = lower_bound(ids.begin(), ids.end(), p[i]) - ids.begin();
    p[i] = x;
    tr.up(x, sum);
  }

  FOR(i, 0, q){
    if(qrs[i].f == '?'){
      x = lower_bound(ids.begin(), ids.end(), qrs[i].s.f) - ids.begin();
      y = lower_bound(ids.begin(), ids.end(), qrs[i].s.s) - ids.begin();
      cout << tr.get(x, y) << "\n";
    }else{
      y = qrs[i].s.f - 1;
      tr.up(p[y], res);
      x = lower_bound(ids.begin(), ids.end(), qrs[i].s.s) - ids.begin();
      tr.up(x, sum);
      p[y] = x;
    }
  }

  return 0;
}