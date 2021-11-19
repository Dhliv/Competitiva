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
 
using namespace std;

struct st{
  int l, r, m, s, v;
  st *left, *right;

  void com(){
    s = left->s + right->s;
  }

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;

    if(l == r){
      s = 1;
      v = p[l];
    }else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  void get(int i){
    if(l == r){
      s = 0;
      cout << v;
      return;
    }
    if(i <= left->s) left->get(i);
    else right->get(i - left->s);
    s--;
  }
};
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n;
  vector<int> p(n + 1);
  FOR(i, 1, n + 1) cin >> p[i];
  st tr(1, n + 1, p);

  FOR(i, 0, n){
    if(i) cout << " ";

    cin >> x;
    tr.get(x);
  }
  
  return 0;
}