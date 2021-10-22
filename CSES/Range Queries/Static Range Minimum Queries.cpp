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
  int l, r, mini, m;
  st *left, *right;

  void com(){
    mini = min(left->mini, right->mini);
  }

  st(int l, int r, vector<int> &p){
    this->l = l;
    this->r = r;

    if(l == r) mini = p[l];
    else{
      m = (l + r)/2;
      left = new st(l, m, p);
      right = new st(m + 1, r, p);
      com();
    }
  }

  int get(int &i, int &j){
    if(r < i or l > j) return INF;
    if(i <= l and r <= j) return mini;
    return min(left->get(i, j), right->get(i, j));
  }
};
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q, x, y;
  cin >> n >> q;
  vector<int> p(n + 1);

  FOR(i, 1, n + 1) cin >> p[i];
  st tr(1, n + 1, p);

  FOR(i, 0, q){
    cin >> x >> y;
    cout << tr.get(x, y) << "\n";
  }

  return 0;
}