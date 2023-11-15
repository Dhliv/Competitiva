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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

struct dt{
  ll val, pos;

  dt(){}
  dt(int val, int pos) : val(val), pos(pos) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, q; cin >> t;

  while(t--){
    cin >> n >> q;
    vector<deque<dt> > pws(40);
    FOR(i, 0, n){
      ll x; cin >> x;
      FOR(j, 0, 40){
        if(x & (1 << j)){
          pws[j].PB(dt(x, i));
          break;
        }
      }
    }

    FOR(i, 0, q){
      int x; cin >> x;

      FORI(j, 30, x){
        while(pws[j].size()){
          dt d = pws[j].F();
          pws[j].P_F();
          d.val |= (1 << x - 1);
          pws[x - 1].PB(d);
        }
      }
    }

    vector<ll> ans(n);
    FOR(i, 0, 31){
      FOR(j, 0, pws[i].size()) ans[pws[i][j].pos] = pws[i][j].val;
    }

    FOR(i, 0, n) cout << ans[i] << " ";
    cout << "\n";
  }

  return 0;
}