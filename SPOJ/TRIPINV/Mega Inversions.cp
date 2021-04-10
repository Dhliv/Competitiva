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
  int l, r, m, sum;
  st *left, *right;
  
  void com(){
    sum = left->sum + right->sum;
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    sum = 0;
    
    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
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
    if(j < l or i > r) return 0;
    if(i <= l and j >= r) return sum;
    return left->get(i, j) + right->get(i, j);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, sum = 1, res = -1, z = 0, x, lim;
  ll a, b, ans;
  cin >> n;
  
  st les(0, n + 2), mas(0, n + 2);
  vector<int> d(n);
  FOR(i, 0, n) cin >> d[i];
  FOR(i, 1, n) les.up(d[i], sum);
  mas.up(d[0], sum);
  
  ans = 0;
  lim = n + 1;
  FOR(i, 1, n - 1){
    x = d[i];
    x++;
    a = mas.get(x, lim);
    x -= 2;
    b = les.get(z, x);
    ans += a*b;
    
    x++;
    mas.up(x, sum);
    les.up(x, res);
  }
  
  cout << ans << "\n";

  return 0;
}