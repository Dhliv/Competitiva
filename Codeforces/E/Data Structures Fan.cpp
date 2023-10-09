#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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
  vector<int> val;
  bool lazy;
  int lval, changes;
  st *left, *right;

  void com(){
    int lf, rh, cur;
    lf = left->val[1];
    rh = right->val[1];
    cur = lf ^ rh;
    val[1] = cur;
    //cout << "Active: " << l << " " << r << " with " << lf << " & " << rh << " -> " << cur << "\n";

    // contrary
    lf = left->val[0];
    rh = right->val[0];
    cur = lf ^ rh;
    val[0] = cur;
    //cout << "Inactive: " << l << " " << r << " with " << lf << " & " << rh << " -> " << cur << "\n";
  }

  st(int l, int r, string &s, vector<int> &p){
    this->l = l;
    this->r = r;
    val.assign(2, 0);

    lval = lazy = changes = false;
    if(l == r){
      if(s[l] == '1') val[1] = p[l];
      else val[0] = p[l];
    }else{
      m = (l + r)/2;
      left = new st(l, m, s, p);
      right = new st(m + 1, r, s, p);
      com();
    }
  }

  void pro(){
    if((lval - changes)%2) swap(val[0], val[1]);
    if(l != r){
      left->lazy = 1;
      left->lval = lval + left->lval;

      right->lazy = 1;
      right->lval = lval + right->lval;
    }
    lazy = changes = lval = 0;
  }

  void up(int &i, int &j){
    if(lazy) pro();
    if(r < i or j < l) return;
    if(i <= l and r <= j){
      lazy = lval = changes = 1;
      swap(val[0], val[1]);
      return;
    }

    left->up(i, j);
    right->up(i, j);
    com();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int l, r, g, q, n, v;
  string s;

  while(t--){
    cin >> n;
    vector<int> a(n); FOR(i, 0, n) cin >> a[i];
    cin >> s >> q;

    st tr(0, n - 1, s, a);

    FOR(i, 0, q){
      cin >> g;
      if(g == 1){
        cin >> l >> r;
        l--; r--;
        tr.up(l, r);
      }else{
        cin >> v;
        cout << tr.val[v] << " ";
      }

      //cout << tr.val[0] << " " << tr.val[1] << "\n";
    }

    cout << "\n";
  }

  return 0;
}