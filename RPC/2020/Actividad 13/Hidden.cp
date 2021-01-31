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

int main(){
  int cases, n, x, y, A, B, C;
  ll ans = 0, res;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    vector<pair<int, int> > p(n);
    ans = 0;
    
    FOR(i, 0, n){
      cin >> x >> y;
      p[i] = MP(x, y);
    }
    
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        FOR(k, j + 1, n){
          A = p[k].s - p[i].s;
          B = p[i].f - p[k].f;
          C = -(p[i].f*A + p[i].s*B);
          res = A*p[j].f + B*p[j].s + C;
          if(res != 0) ans++;
        }
      }
    }
    
    cout << ans << "\n";
  }

  return 0;
}