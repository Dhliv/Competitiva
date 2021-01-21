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
  
  void clear(){
    sum = 0;
    if(l == r) return;
    left->clear();
    right->clear();
    return;
  }
  
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
  
  void up(int &i){
    if(l == r) sum++;
    else{
      if(i <= m) left->up(i);
      else right->up(i);
      sum++;
    }
    return;
  }
  
  int get(int &i, int &j){
    if(i > r or j < l) return 0;
    if(i <= l and r <= j) return sum;
    return (left->get(i, j) + right->get(i, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, x, c = 0, fin;
  ll ans = 0;
  cin >> n;
  fin = n - 1;
  vector<pair<int, int> > p(n);
  vector<int> q(n), af(n);
  vector<ll> bef(n);
  
  FOR(i, 0, n){
    cin >> x;
    p[i] = MP(x, i);
  }
  
  sort(p.begin(), p.end());
  FOR(i, 0, n) q[p[i].s] = i;
  st tr(0, fin);
  
  FOR(i, 0, n){
    x = q[i] + 1;
    if(q[i] != fin) bef[i] = tr.get(x, fin);
    tr.up(q[i]);
  }
  
  tr.clear();
  FORI(i, fin, 0){
    x = q[i] - 1;
    if(q[i]) af[i] = tr.get(c, x);
    tr.up(q[i]);
  }
  
  FOR(i, 0, n) ans += af[i]*bef[i];
  
  cout << ans << "\n";
  
  return 0;
}