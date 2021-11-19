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
  int l, r, m, maxi;
  st *left, *right;

  void com(){
    maxi = max(left->maxi, right->maxi);
  }

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;

    if(l == r) maxi = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  void get(int &v){
    if(l == r){
      cout << l;
      maxi -= v;
      return;
    }
    if(left->maxi >= v) left->get(v);
    else right->get(v);
    com();
    return;
  }
};
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x;
  cin >> n >> m;
  vector<int> p(n + 1);
  FOR(i, 1, n + 1) cin >> p[i];
  st tr(1, n + 1, p);

  FOR(i, 0, m){
    if(i) cout << " ";
    
    cin >> x;
    if(tr.maxi < x) cout << 0;
    else tr.get(x);
  }
  
  return 0;
}