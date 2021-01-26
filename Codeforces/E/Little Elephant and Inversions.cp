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
  
  void up(int &i, int &v){
    if(l == r) sum += v;
    else{
      if(i <= m) left->up(i, v);
      else right->up(i, v);
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
  int n, x, id, sum = 1, res = -1, pl, pr, c = 0, y;
  ll k, Tl, Tr, pares = 0;
  cin >> n >> k;
  vector<int> q(n);
  vector<pair<int, int> > p(n);
  FOR(i, 0, n){
    cin >> x;
    p[i] = MP(x, i);
  }
  
  sort(p.begin(), p.end());
  
  id = 0;
  x = p[0].f;
  q[p[0].s] = id;
  FOR(i, 1, n){
    if(x == p[i].f) q[p[i].s] = id;
    else{
      x = p[i].f;
      id++;
      q[p[i].s] = id;
    }
  }
  
  st tl(0, id), tr(0, id);
  Tl = Tr = 0;
  FOR(i, 0, n - 1){
    if(q[i] < id){
      x = q[i] + 1;
      Tl += tl.get(x, id);
    }
    tl.up(q[i], sum);
  }
  if(q[n - 1] < id){
    x = q[n - 1] + 1;
    Tr = tl.get(x, id);
  }
  tr.up(q[n - 1], sum);
  pr = n - 1;
  
  FORI(i, pr - 1, 0){
    if(Tl + Tr <= k){
      pares += (i + 1);
      pr--;
      
      if(i == pr){
        if(q[i] < id){
          x = q[i] + 1;
          y = tl.get(x, id);
          Tl -= y;
          Tr += y;
        }
        tl.up(q[i], res);
        tr.up(q[i], sum);
      }else{
        if(q[pr] > 0){
          x = q[pr] - 1;
          Tr += tr.get(c, x);
        }
        if(q[pr] < id){
          x = q[pr] + 1;
          Tr += tl.get(x, id);
        }
        tr.up(q[pr], sum);
        i++;
      }
    }else{
      if(q[i] < id){
        x = q[i] + 1;
        Tl -= tl.get(x, id);
      }
      tl.up(q[i], res);
      if(q[i]){
        x = q[i] - 1;
        Tr -= tr.get(c, x);
      }
    }
  }
  
  cout << pares << "\n";
  
  return 0;
}