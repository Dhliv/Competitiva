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

struct st{
  int l, r, m, sum;
  st *left, *right;

  void com() {
    sum = left->sum + right->sum;
  }

  st(int l, int r, vector<int> &p) {
    this->l = l;
    this->r = r;
    sum = 0;

    if(l == r) sum = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  int get(int &i, int &j) {
    if(j < l or i > r) return 0;
    if(i <= l and r <= j) return sum;
    return left->get(i, j) + right->get(i, j);
  } 

  void change(int &x) {
    if(l == r) {
      sum = sum > 0 ? 0 : 1;
      return;
    }
    if(x <= m) left->change(x);
    else right->change(x);
    com();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y, ax, bx, q, zero = 0; cin >> n >> m >> q;
  string s;
  vector<int> p(n*m, 0);

  FOR(i, 0, n){
    cin >> s;
    FOR(j, 0, m){
      if(s[j] == '*'){
        p[n*j + i] = 1;
      }
    }
  }

  st tr(0, n*m - 1, p);

  FOR(i, 0, q){
    cin >> x >> y;
    x--; y--;
    ax = y*n + x;

    tr.change(ax);
    bx = tr.sum - 1;
    if(bx < 0) cout << "0\n";
    else cout << tr.sum - tr.get(zero, bx) << "\n";
  }
  
  return 0;
}
