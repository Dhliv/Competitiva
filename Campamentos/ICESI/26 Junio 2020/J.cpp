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

vector<ll> arr;

struct st{
  int l, r, lval, rval, op, value, m;
  st *left, *right;
  st(int a, int b, int n){
    this->l = a;
    this->r = b;
    this->op = n%2;

    if(abs(l - r) != 1){
      m = (l + r)/2;
      left = new st(l, m, n-1);
      right = new st(m+1, r, n-1);

      this->lval = left->value;
      this->rval = right->value;
      
      if(this->op)
        this->value = this->lval | this->rval;
      else
        this->value = this->lval ^ this->rval;
    }else{
      this->lval = arr[l];
      this->rval = arr[r];
      
      if(this->op)
        this->value = this->lval | this->rval;
      else
        this->value = this->lval ^ this->rval;
    }
  }
  
  void update(int pos, int abc){
    if(abs(l - r) == 1){
      if(pos == l)
        lval = abc;
      else
        rval = abc;
      
      if(op)
        value = (lval | rval);
      else
        value = (lval ^ rval);
    }
    else{
      if(pos <= m)
        left->update(pos, abc);
      else
        right->update(pos, abc);
      
      lval = left->value;
      rval = right->value;
      
      if(op)
        value = (lval | rval);
      else
        value = (lval ^ rval);
    }
  }
};

int main() {
  int n, quers, total, pos, val;
  cin >> n >> quers;
  total = pow(2, n);
  arr.resize(total); 
  
  FOR(i, 0, total)
    cin >> arr[i];

  st arbol(0, total - 1, n);
  
  FOR(i, 0, quers){
    cin >> pos >> val;
    arbol.update(pos - 1, val);
    cout << arbol.value << "\n";
  }
  
  return 0;
}