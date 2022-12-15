#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

struct st{
  int l, r, m;
  ull sum, val;
  bool lazy;
  st *left, *right;

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;
    val = lazy = 0;

    if(l == r) sum = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
    }
  }

  void pro(){
    lazy = 0;
    if(l == r) sum += val;
    else{
      left->lazy = 1;
      left->val += val;

      right->lazy = 1;
      right->val += val;
    }
    val = 0;
  }

  void up(int &i, int &j, ull x){
    if(lazy) pro();

    if(j < l or i > r) return;
    if(i <= l and r <= j){
      lazy = 1;
      val += x;
      return;
    }

    left->up(i, j, x);
    right->up(i, j, x);
  }

  ull get(int i){
    if(lazy) pro();

    if(l == r) return sum;
    else{
      if(i <= m) return left->get(i);
      return right->get(i);
    }
  }
};

struct dt{
  int l, r, x;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k, uno = 1; cin >> n >> m >> k;
  vector<int> p(n + 1); FOR(i, 1, n + 1) cin >> p[i];

  st tr(1, n, p);
  vector<dt> q(m + 1);

  int l, r, x;
  FOR(i, 1, m + 1){
    cin >> q[i].l >> q[i].r >> q[i].x;
  }

  vector<int> aux(m + 1, 0);
  st op(1, m, aux);

  FOR(i, 0, k){
    cin >> l >> r;
    op.up(l, r, uno);
  }

  FOR(i, 1, m + 1){
    ull qnt = op.get(i);

    ull ax = q[i].x*qnt;
    tr.up(q[i].l, q[i].r, ax);
  }

  FOR(i, 1, n + 1){
    cout << tr.get(i) << " ";
  }
  cout << "\n";

  return 0;
}