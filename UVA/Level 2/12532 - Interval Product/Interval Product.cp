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
  int l, r, m, p;
  st *left, *right;
  
  st(int l, int r, vector<int> &data){
    this->l = l;
    this->r = r;
    this->m = (l + r)/2;
    
    if(l == r) this->p = (data[l - 1] == 0) ? 0 : (data[l - 1] > 0) ? 1 : -1;
    else{
      left = new st(l, m, data);
      right = new st(m + 1, r, data);
      this->p = left->p*right->p;
    }
  }
  
  void update(int &i, int &val){
    if(l == r and l == i) this->p = (val == 0) ? 0 : (val > 0) ? 1 : -1;
    else if(i <= m){
      left->update(i, val);
      this->p = right->p*left->p;
    }else{
      right->update(i, val);
      this->p = right->p*left->p;
    }
  }
  
  int get(int &i, int &j){
    if(i > r or j < l) return 1;
    if(i <= l and j >= r) return this->p;
    return left->get(i, j)*right->get(i, j);
  }
};

int main(){
  int n, m, x, y, c;
  char k;
  
  while(cin >> n >> m){
    vector<int> data(n);
    FOR(i, 0, n) cin >> data[i];
    st tr(1, n, data);
    
    FOR(i, 0, m){
      cin >> k;
      
      if(k == 'C'){
        cin >> x >> c;
        tr.update(x, c);
      }else{
        cin >> x >> y;
        c = tr.get(x, y);
        cout << ((c == 0) ? '0' : (c > 0) ? '+' : '-');
      }
    }
    
    cout << "\n";
  }

  return 0;
}