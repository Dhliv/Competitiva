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

int mitad;

struct all{
  int seg, suf, nsuf, pre, npre;
  
  void ini(int a){
    seg = suf = pre = 1;
    npre = nsuf = a;
  }
};

all INV, ans;

struct st{
  int l, r, m;
  all h;
  st *left, *right;
  
  void com(all &a, all &b, bool ch){
    if(ch){
      h.suf = (b.nsuf == a.nsuf) ? b.suf + a.suf : b.suf;
      h.pre = (a.npre == b.npre) ? a.pre + b.pre : a.pre;
      h.npre = a.npre;
      h.nsuf = b.nsuf;
      mitad = (a.nsuf == b.npre) ? a.suf + b.pre : a.suf;
      h.seg = max({a.seg, b.seg, mitad});
    }else{
      ans.suf = (b.nsuf == a.nsuf) ? b.suf + a.suf : b.suf;
      ans.pre = (a.npre == b.npre) ? a.pre + b.pre : a.pre;
      ans.npre = a.npre;
      ans.nsuf = b.nsuf;
      mitad = (a.nsuf == b.npre) ? a.suf + b.pre : a.suf;
      ans.seg = max({a.seg, b.seg, mitad});
    }
  }
  
  st(int l, int r, vector<int> &data){
    this->l = l;
    this->r = r;
    
    if(l == r) h.ini(data[l - 1]);
    else{
      m = (l + r)/2;
      left = new st(l, m, data);
      right = new st(m + 1, r, data);
      com(left->h, right->h, true);
    }
  }
  
  all get(int &i, int &j){
    if(i > r or j < l) return INV;
    if(i <= l and j >= r) return h;
    
    all ax, bx;
    ax = (left->get(i, j));
    bx = (right->get(i, j));
    if(ax.npre == INF) return bx;
    if(bx.npre == INF) return ax;
    com(ax, bx, false);
    return ans;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, x, y;
  INV.ini(INF);
  
  while(cin >> n, n){
    cin >> m;
    vector<int> data(n);
    FOR(i, 0, n) cin >> data[i];
    
    st tr(1, n, data);
    
    FOR(i, 0, m){
      cin >> x >> y;
      cout << tr.get(x, y).seg << "\n";
    }
  }

  return 0;
}