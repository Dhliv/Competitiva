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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

struct st{
  int l, r, color, m, laz;
  st *left, *right;
  st(int a, int b){
    this->l = a;
    this->r = b;
    this->laz = 0;
    this->color = 0;

    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m+1, r);
    }
  }
  
  void propagate(){
    if(laz != 0){
      color = laz;
      if(l != r){
        left->laz = laz;
        right->laz = laz;
      }
      laz = 0;
    }
  }

  void update(int a, int b, int val){
    propagate();
    if(b < l or a > r) return;
    if(a <= l and b >= r){
      laz = val;
      propagate();
      return;
    }
    left->update(a, b, val);
    right->update(a, b, val);
  }

  void impr(){
    propagate();
    if(l == r)
      cout << color << "\n";
    else{
      left->impr();
      right->impr();
    }
  }
};

int main() {
  int n, q, col, l, r;
  cin >> n >> q;
  st reja(0, n-1);
  
  FOR(i, 0, q){
    cin >> l >> r >> col;
    reja.update(l - 1, r - 1, col);
  }
  
  reja.impr();
  
  return 0;
}