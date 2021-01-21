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
  int l, r, m, sum;
  st *left, *right;
  
  void com(){ sum = left->sum + right->sum;}
  
  void clear(){
    if(l == r) sum = 1;
    else{
      left->clear();
      right->clear();
      com();
    }
    return;
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    
    if(l == r) sum = 1;
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      com();
    }
  }
  
  void up(int &i){
    if(l == r) sum = 0;
    else{
      if(i <= m) left->up(i);
      else right->up(i);
      com();
    }
    return;
  }
  
  int get(int &i, int &j){
    if(i > r or j < l) return 0;
    if(i <= l and r <= j) return sum;
    return (left->get(i, j) + right->get(i, j));
  }
  
  int num(int v){
    if(l == r) return l;
    if(v <= left->sum) return left->num(v);
    return right->num(v - left->sum);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, x, c = 0, ax;
  cin >> n;
  vector<int> ansA(n), ansB(n), ans(n);
  st tr(0, n - 1);
  
  FOR(i, 0, n){
    cin >> x;
    tr.up(x);
    ansA[i] = tr.get(c, x);
  }
  
  tr.clear();
  
  FOR(i, 0, n){
    cin >> x;
    tr.up(x);
    ansB[i] = tr.get(c, x);
  }
  
  tr.clear();
  
  ax = 0;
  FORI(i, n - 1, 0){
    x = ax + ansA[i] + ansB[i];
    ans[i] = x%(n - i) + 1;
    ax = (x/(n - i)) ? 1 : 0;
  }
  
  FOR(i, 0, n){
    x = tr.num(ans[i]);
    tr.up(x);
    cout << x << " ";
  }
  
  return 0;
}