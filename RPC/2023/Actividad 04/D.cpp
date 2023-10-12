#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;

struct rng{
  int l, h;

  rng(){}
  rng(int l, int h) : l(l), h(h){}
};
 
const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k; cin >> n >> k;
  vector<vector<rng> > algo(n, vector<rng> (k));

  vector<int> sn(n, 0);
  deque<int> q;
  FOR(i, 0, n){
    FOR(j, 0, 2){
      FOR(l, 0, k){
        if(j) cin >> algo[i][l].h;
        else cin >> algo[i][l].l;
      }
    }
  }

  FOR(i, 0, n){
    bool able = true;
    FOR(j, 0, k){
      if(algo[i][j].l > 0){
        able = false;
        break;
      }
    }

    if(able){
      q.PB(i);
      sn[i] = 1;
    }
  }

  bool able;
  vector<vector<int> > g(n);
  FOR(i, 0, n){
    FOR(j, 0, n){
      if(i == j) continue;

      able = true;
      FOR(l, 0, k){
        if(algo[i][l].h < algo[j][l].l){
          able = false;
          break;
        }
      }

      if(able) g[i].PB(j);
    }
  }

  int x;
  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y: g[x]){
      if(sn[y]) continue;
      sn[y] = 1;
      q.PB(y);
    }
  }

  int ans = 0;
  FOR(i, 0, n) ans += sn[i];

  cout << ans << "\n";

  return 0;
}