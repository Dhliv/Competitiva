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
#define dat pair<int, pair<int, int> >
#define MAX 201

using namespace std;

int lim, lo;
vector<int> A, B;

struct st{
  int l, r, m, nm, nl, nr, v;
  bool lazy;
  st *left, *right;
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    lazy = 0;
    
    if(l == r) v = B[l - 1];
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
  }
  
  void pro(){
    lazy = 0;
    if(l == r) v = A[nl - 1];
    else{
      nm = (nl + nr)/2;
      if(!left->lazy) left->lazy = 1;
      left->nl = nl;
      left->nr = nm;
      if(!right->lazy) right->lazy = 1;
      right->nl = nm + 1;
      right->nr = nr;
    }
    return;
  }
  
  void up(int &i, int &j){
    if(lazy) pro();
    if(i > r or j < l) return;
    if(i <= l and r <= j){
      nl = lim;
      nr = r - l + lim;
      lim += (r - l + 1);
      lazy = 1;
      return;
    }
    left->up(i, j);
    right->up(i, j);
    return;
  }
  
  int get(int &i){
    if(lazy) pro();
    if(l == r) return v;
    if(i <= m) return left->get(i);
    return right->get(i);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, t, x, y, k;
  cin >> n >> m;
  A.resize(n);
  B.resize(n);
  FOR(i, 0, n) cin >> A[i];
  FOR(i, 0, n) cin >> B[i];
  
  st tr(1, n);
  
  FOR(i, 0, m){
    cin >> t;
    if(t == 2){
      cin >> x;
      cout << tr.get(x) << "\n";
    }else{
      cin >> lim >> x >> k;
      y = x + k - 1;
      tr.up(x, y);
    }
  }
  
  return 0;
}