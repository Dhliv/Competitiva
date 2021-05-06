#include <bits/stdc++.h>
#define INF LLONG_MAX
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

int ans, pos;
bool fn;

struct st{
  int l, r, m, sum;
  bool ch;
  st *left, *right;
  
  void com(){
    sum = left->sum + right->sum;
  }
  
  void up(){
    right->sum = sum - left->sum;
    right->ch = true;
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    sum = 0;
    ch = 0;
    if(l != r){
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
    }
  }
  
  void check(){
    ch = true;
    cout << "? " << l << " " << r << endl;
    cin >> ans;
    sum = r - l + 1 - ans;
    return;
  }
  
  void find(int k){
    if(!ch) check();
    if(k > sum) return;
    if(l == r){
      fn = true;
      pos = l;
    }else{
      if(k <= sum) left->find(k);
      up();
      if(!fn) right->find(k - left->sum);
    }
    return;
  }
  
  void res(int &i){
    if(l == r) sum = 0;
    else{
      if(i <= m) left->res(i);
      else right->res(i);
      com();
    }
    return;
  }
  
  void show(){
    cout << "(" << l << ", " << r << ") ->  ";
    cout << "sum: " << sum << "; check: " << ch << "\n";
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
  
  int n, l, r, t, m, k;
  cin >> n >> t;
  
  st tr(1, n);
  
  FOR(ab, 0, t){
    cin >> k;
    fn = false;
    tr.find(k);
    cout << "! " << pos << endl;
    tr.res(pos);
  }
  
  //tr.show();
  
  return 0;
}