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
#define MAX 100010

using namespace std;

int p[MAX];
deque<int> q, ord;

struct st{
  int l, r, m, mini;
  st *left, *right;
  
  void com(){
    mini = min(left->mini, right->mini);
  }
  
  st(int l, int r){
    this->l = l;
    this->r = r;
    
    if(l == r) mini = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m);
      right = new st(m + 1, r);
      com();
    }
  }
  
  int get(int &i, int &j){
    if(j < l or i > r) return INF;
    if(i <= l and r <= j) return mini;
    return min(left->get(i, j), right->get(i, j));
  }
  
  void up(int &i, int &j){
    if(j < l or i > r or q.empty()) return;
    if(q.F() < l or q.F() > r) return;
    
    if(l == r and l == q.F()){
      q.P_F();
      mini = ord.F();
      p[l] = mini;
      ord.P_F();
      return;
    }
    
    left->up(i, j);
    right->up(i, j);
    com();
    return;
  }
  
  void show(){
    cout << "(" << l << ", " << r << ") ->  ";
    cout << "mini: " << mini << "\n";
    if(l != r){
      left->show();
      right->show();
    }
    return;
  } 
};

void trf(string &a){
  a.PB(',');
  int pos = 0;
  FOR(i, 0, a.size()){
    if(a[i] == ','){
      q.PB(stoi(a.substr(pos, i - pos)));
      i++;
      pos = i;
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, x, y;
  string a;
  char t;
  cin >> n >> m;
  FOR(i, 1, n + 1) cin >> p[i];
  
  st tr(1, n);
  
  FOR(ab, 0, m){
    cin >> a;
    t = a[0];
    a = a.substr(6, a.size() - 7);
    trf(a);
    
    if(t == 'q'){
      x = q[0];
      y = q[1];
      q.P_F(); q.P_F();
      
      cout << tr.get(x, y) << "\n";
    }else{
      FOR(i, 1, q.size()) ord.PB(p[q[i]]);
      ord.PB(p[q[0]]);
      
      x = q.F();
      y = q.B();
      tr.up(x, y);
    }
    q.clear();
    ord.clear();
  }
  
  //tr.show();
  
  return 0;
}