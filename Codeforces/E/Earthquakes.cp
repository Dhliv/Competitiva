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
#define MAX 40000

using namespace std;

int x;

struct st{
  int l, r, m, edificios, maxi, mini;
  bool lazy;
  st *left, *right;
  
  void com(){
    edificios = left->edificios + right->edificios;
    maxi = max(left->maxi, right->maxi);
    mini = min(left->mini, right->mini);
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    lazy = edificios = maxi = 0;
    mini = INF;
    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
  }
  
  void pro(){
    lazy = 0;
    maxi = edificios = 0;
    mini = INF;
    if(l != r){
      left->lazy = 1;
      left->edificios = 0;
      left->maxi = 0;
      left->mini = INF;
      
      right->lazy = 1;
      right->edificios = 0;
      right->maxi = 0;
      right->mini = INF;
    }
    return;
  }
  
  void build(int &i, int &h){
    if(lazy) pro();
    if(l == r){
      maxi = mini = h;
      edificios = 1;
    }else{
      if(i <= m) left->build(i, h);
      else right->build(i, h);
      com();
    }
    return;
  }
  
  int destroy(int &i, int &j, int &p){
    if(lazy) pro();
    if(j < l or i > r or edificios == 0 or mini > p) return 0;
    if(i <= l and r <= j and p >= maxi){
      lazy = 1;
      x = edificios;
      edificios = maxi = 0;
      mini = INF;
      return x;
    }
    x = left->destroy(i, j, p) + right->destroy(i, j, p);
    com();
    return x;
  }
  
  void show(){
    //if(lazy) pro();
    cout << "(" << l << ", " << r << ") ->  ";
    cout << "maxi: " << maxi << "; edificios: " << edificios << "; mini: " << mini << "\n";
    if(l != r){
      left->show();
      right->show();
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, t, x, y, p, h;
  cin >> n >> m;
  st tr(0, n - 1);
  
  FOR(i, 0, m){
    cin >> t;
    if(t == 1){
      cin >> x >> h;
      tr.build(x, h);
    }else{
      cin >> x >> y >> p;
      y--;
      cout << tr.destroy(x, y, p) << "\n";
    }
  }
  
  //tr.show();
  
  return 0;
}