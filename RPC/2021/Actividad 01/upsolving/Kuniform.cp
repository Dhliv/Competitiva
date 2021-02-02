#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

bool comp(pair<int, int> &a, pair<int, int> b){
  if(a.s < b.s) return true;
  else if(a.s == b.s) return a.f < b.f;
  return false;
}

struct st{
  int l, r, m, s;
  st *left, *right;
  
  void com(){
    s = left->s + right->s;
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    
    if(l == r) s = 0;
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      s = 0;
    }
  }
  
  void up(int &i, int &v){
    if(l == r) s += v;
    else{
      if(i <= m) left->up(i, v);
      else right->up(i, v);
      com();
    }
    return;
  }
  
  int get(int &i, int &j){
    if(i > r or j < l) return 0;
    if(i <= l and r <= j) return s;
    return (left->get(i, j) + right->get(i, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, id, x, mini, sum = 1, res = -1, ax;
  cin >> n >> k;
  
  if(k == 1) cout << "0\n";
  else{
    deque<pair<int, int> > p(n);
    vector<int> q(n);
    
    ax = 0;
    FOR(i, 0, n){
      cin >> x;
      p[i] = MP(x, i);
      if(x == 2) ax++;
    }
    
    sort(p.begin(), p.end());
    id = 0;
    x = p[0].f;
    FOR(i, 0, n){
      if(x == p[i].f) q[p[i].s] = id;
      else{
        id++;
        x = p[i].f;
        q[p[i].s] = id;
      }
    }
    
    deque<deque<int> > pos(id + 1);
    deque<pair<int, int> > org;
    FOR(i, 0, n) pos[q[i]].PB(i);
    FOR(i, 0, id + 1){
      if(pos[i].size() >= k){
        x = k - 1;
        FOR(j, x, pos[i].size()) org.PB(MP(pos[i][j - x], pos[i][j]));
      }
    }
    
    sort(org.begin(), org.end(), comp);
    
    vector<int> se(id + 1, -1);
    st tr(0, n - 1);
    x = 0;
    mini = INF;
    FOR(i, 0, org.size()){
      if(x <= org[i].s){
        FOR(j, x, org[i].s + 1){
          if(se[q[j]] != -1) tr.up(se[q[j]], res);
          se[q[j]] = j;
          ax = j;
          if(j == org[i].s) mini = min(mini, tr.get(org[i].f, org[i].s));
          tr.up(ax, sum);
        }
        x = org[i].s + 1;
      }
    }
    
    if(mini != INF) cout << mini << "\n";
    else cout << "-1\n";
  }
  
  return 0;
}