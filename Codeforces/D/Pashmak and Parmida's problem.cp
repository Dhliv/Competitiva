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

vector<int> all;

struct st{
  int l, r, m, sum;
  st *left, *right;
  
  void com(){ sum = left->sum + right->sum;}
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    
    if(l == r) sum = all[l];
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      com();
    }
  }
  
  void up(int &i){
    if(l == r) sum--;
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
};

int main(){
  ios_base::sync_with_stdio(false);
  int n, x, l = 1000000, u = 1;
  ll ans;
  cin >> n;
  map<int, vector<int> > d;
  vector<int> ax(1), q(n), p(n), ori(n);
  all.resize(l + 1);
  
  FOR(i, 0, n){
    cin >> x;
    ori[i] = x;
    if(d.find(x) == d.end()){
      ax[0] = i;
      d.insert(MP(x, ax));
      q[i] = 1;
    }else{
      d[x].PB(i);
      q[i] = d[x].size();
    }
  }
  
  FOR(i, 0, n){
    p[i] = d[ori[i]].size() - q[i] + 1;
    all[p[i]]++;
  }
  
  st tr(1, l);
  
  ans = 0;
  FOR(i, 0, n){
    tr.up(p[i]);
    if(q[i] > 1){
      x = q[i] - 1;
      ans += tr.get(u, x);
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}