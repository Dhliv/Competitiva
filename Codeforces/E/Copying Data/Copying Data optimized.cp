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

int x;
vector<int> a, b;

struct st{
  int l, r, m, pos, val;
  bool lazy;
  st *left, *right;
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    
    if(l == r) val = b[l];
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
    lazy = 0;
  }
  
  void pro(){
    lazy = false;
    if(l == r){
      val = a[pos];
    }else{
      left->lazy = true;
      right->lazy = true;
      left->pos = pos;
      pos += (left->r - left->l + 1);
      right->pos = pos;
    }
    return;
  }
  
  void up(int &i, int &j){
    if(lazy) pro();
    if(j < l or i > r) return;
    if(i <= l and r <= j){
      lazy = true;
      pos = x;
      x += (r - l + 1);
    }else{
      left->up(i, j);
      right->up(i, j);
    }
    return;
  }
  
  int get(int &i){
    if(lazy) pro();
    if(l == r) return val;
    else{
      if(i <= m) return left->get(i);
      return right->get(i);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, t, y, k, upto;
  cin >> n >> m;
  a.resize(n);
  b.resize(n);
  
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  st tr(0, n - 1);
  
  FOR(i, 0, m){
    cin >> t;
    if(t == 1){
      cin >> x >> y >> k;
      x--;
      y--;
      upto = y + k - 1;
      tr.up(y, upto);
    }else{
      cin >> x;
      x--;
      cout << tr.get(x) << "\n";
    }
  }
  
  return 0;
}