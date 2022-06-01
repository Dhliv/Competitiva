#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, x; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(n), sp; FOR(i, 0, n) cin >> p[i];
    vector<int> q(n), sq; FOR(i, 0, n) cin >> q[i];
    sp = p; sq = q;
    sort(sq.begin(), sq.end());
    sort(sp.begin(), sp.end());

    deque<pair<int, int> > ops;

    FOR(i, 0, n - 1){
      if(sp[i] != p[i] or sq[i] != q[i]){
        FOR(j, i + 1, n){
          if(sp[i] == p[j] and sq[i] == q[j]){
            ops.PB(MP(i + 1, j + 1));
            swap(p[i], p[j]);
            swap(q[i], q[j]);
          }
        }
      }
    }

    if(p == sp and q == sq){
      cout << ops.size() << "\n";
      FOR(i, 0, ops.size()) cout << ops[i].f << " " << ops[i].s << "\n";
    }else cout << "-1\n";
  }

  return 0;
}