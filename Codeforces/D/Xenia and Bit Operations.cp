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

struct st{
  int l, r, m, val;
  bool op;
  st *left, *right;
  
  void com(){
    if(op) val = left->val ^ right->val;
    else val = left->val | right->val;
  }
  
  st(int l, int r, vector<int> &data){
    this->l = l;
    this->r = r;
    
    if(l == r){
      val = data[l - 1];
      op = 1;
    }else{
      m = (l + r)/2;
      left = new st(l, m, data);
      right = new st(m + 1, r, data);
      op = 1 - left->op;
      com();
    }
  }
  
  void up(int &i, int &v){
    if(l == r) val = v;
    else{
      if(i <= m) left->up(i, v);
      else right->up(i, v);
      com();
    }
    return;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int k, m, x, c, n = 1;
  cin >> k >> m;
  FOR(i, 0, k) n *= 2;
  
  vector<int> data(n);
  FOR(i, 0, n) cin >> data[i];
  
  st tr(1, n, data);
  
  FOR(i, 0, m){
    cin >> x >> c;
    tr.up(x, c);
    cout << tr.val << "\n";
  }
  
  return 0;
}