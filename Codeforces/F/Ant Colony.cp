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

int k, s;

pair<int, int> com(pair<int, int> a, pair<int, int> b){
  k = __gcd(a.f, b.f);
  s = 0;
  if(k == a.f) s += a.s;
  if(k == b.f) s += b.s;
  
  return MP(k, s);
}

struct st{
  int l, r, m, v, sum;
  st *left, *right;
  
  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;
    
    if(l == r){
      v = p[l - 1];
      sum = 1;
    }else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      v = __gcd(left->v, right->v);
      sum = 0;
      if(v == left->v) sum += left->sum;
      if(v == right->v) sum += right->sum;
    }
  }
  
  pair<int, int> get(int &i, int &j){
    if(i <= l and r <= j) return MP(v, sum);
    if(i > right->r or j < right->l) return left->get(i, j);
    if(i > left->r or j < left->l) return right->get(i, j);
    return com(left->get(i, j), right->get(i, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, x, y;
  cin >> n;
  vector<int> p(n);
  FOR(i, 0, n) cin >> p[i];
  
  st tr(1, n, p);
  cin >> m;
  
  FOR(i, 0, m){
    cin >> x >> y;
    cout << (y - x + 1 - tr.get(x, y).s) << "\n";
  }
  
  return 0;
}