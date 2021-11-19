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
  ll v, val;
  bool lazy;
  st *left, *right;

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;
    lazy = 0;
    val = 0;

    if(l == r) v = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
    }
  }

  void pro(){
    lazy = 0;
    if(l == r) v += val;
    else{
      if(left->lazy) left->val += val;
      else{
        left->lazy = 1;
        left->val = val;
      }

      if(right->lazy) right->val += val;
      else{
        right->lazy = 1;
        right->val = val;
      }
    }
    val = 0;
  }

  void up(int &a, int &b, ll &aug){
    if(lazy) pro();
    if(r < a or l > b) return;
    if(a <= l and r <= b){
      lazy = 1;
      val += aug;
      return;
    }

    left->up(a, b, aug);
    right->up(a, b, aug);
    return;
  }

  ll get(int &i){
    if(lazy) pro();
    if(l == r) return v;
    if(i <= m) return left->get(i);
    return right->get(i);
  }
};
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q, t, x, y;
  ll val;
  cin >> n >> q;
  vector<int> p(n + 1);

  FOR(i, 1, n + 1) cin >> p[i];
  st tr(1, n + 1, p);

  FOR(i, 0, q){
    cin >> t;
    if(t == 2){
      cin >> x;
      cout << tr.get(x) << "\n";
    }else{
      cin >> x >> y >> val;
      tr.up(x, y, val);
    }
  }

  return 0;
}