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

  int get(int i, int j){
    if(r < i or l > j) return 0;
    if(i <= l and r <= j) return maxi;
    return max(left->get(i, j), right->get(i, j));
  }
};
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, t, c; cin >> n >> t >> c;
  vector<int> p(n);

  FOR(i, 0, n) cin >> p[i];
  st tr(0, n - 1, p);

  int ans = 0;
  FOR(i, 0, n - c + 1){
    if(tr.get(i, i + c - 1) <= t) ans++;
  }

  cout << ans << "\n";
 
  return 0;
} 