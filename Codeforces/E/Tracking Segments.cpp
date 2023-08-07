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

struct range{
  int l, r;
  range(){}

  int len(){
    return r - l + 1;
  }
};

struct st{
  int l, r, m, sum;
  st *left, *right;

  st(int l, int r){
    this->l = l;
    this->r = r;

    if(l == r) sum = 0;
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      sum = 0;
    }
  }

  void com(){
    sum = left->sum + right->sum;
  }

  void up(int &x, int &val){
    if(l == r) sum += val;
    else{
      if(x <= m) left->up(x, val);
      else right->up(x, val);
      com();
    }
  }

  int get(int &i, int &j){
    if(r < i) return 0;
    if(l > j) return 0;
    if(i <= l and r <= j) return sum;
    return left->get(i, j) + right->get(i, j);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, rn, l, r, m, x, y, p, ch;
  int uno = 1, muno = -1;

  while(t--){
    cin >> n >> rn;
    vector<range> ranges(rn);
    FOR(i, 0, rn) cin >> ranges[i].l >> ranges[i].r;

    cin >> ch;
    vector<int> changes(ch);
    FOR(i, 0, ch) cin >> changes[i];
    st tr(1, n + 1);

    l = 0, r = ch - 1;
    p = -1;
    bool able, move;
    while(l <= r){
      m = (l + r)/2;
      able = false;
      move = false;

      while(p < m){
        move = true;
        tr.up(changes[p + 1], uno);
        p++;
      }

      while(p > m and !move){
        tr.up(changes[p], muno);
        p--;
      }

      FOR(i, 0, rn) able |= 2*tr.get(ranges[i].l, ranges[i].r) > ranges[i].len();

      if(able) r = m - 1;
      else l = m + 1;
    }

    if(l == ch) cout << "-1\n";
    else cout << l + 1 << "\n";
  }
 
  return 0;
}