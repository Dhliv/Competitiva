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

string t;
vector<int> s(20), r, pos(20);

struct st{
  int d, sum, p;
  char id;
  st *left, *right;
  
  void com(){
    if(d == 0){
      sum = 1;
      if(id == '?') sum = 2;
    }else{
      if(id == '?') sum = left->sum + right->sum;
      else if(id == '1') sum = right->sum;
      else sum = left->sum;
    }
  }
  
  st(int d){
    this->d = d;
    p = s[d]++;
    id = t[p - 1];
    
    if(d > 0){
      left = new st(d - 1);
      right = new st(d - 1);
    }
    com();
  }
  
  void up(char &c, int &depth){
    if(d == depth) id = c;
    else{
      if(left->p == pos[d - 1]) left->up(c, depth);
      else right->up(c, depth);
    }
    com();
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int k, q, p, n = 1, d;
  char c;
  cin >> k >> t >> q;
  
  FOR(i, 0, k - 1) n *= 2;
  
  s[0] = 1;
  FOR(i, 1, k){
    s[i] = n + s[i - 1];
    n /= 2;
  }
  
  r = s;
  
  k--;
  st tr(k);
  
  FOR(ab, 0, q){
    cin >> p >> c;
    
    d = k;
    FOR(i, 1, k + 1){
      if(p < r[i]){
        d = i - 1;
        break;
      }
    }
    
    pos[d] = p;
    FOR(i, d + 1, k) pos[i] = (pos[i - 1] - r[i - 1])/2 + r[i];
    
    tr.up(c, d);
    cout << tr.sum << "\n";
  }

  return 0;
}