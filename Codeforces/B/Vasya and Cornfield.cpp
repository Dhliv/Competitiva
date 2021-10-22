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

struct rt {
  int A, B, C;

  void ini(int x0, int y0, int x1, int y1){
    A = y0 - y1;
    B = x1 - x0;
    C = -B*y0 - A*x0;
  }

  int f(int x, int y){
    return A*x + B*y + C;
  }
};
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<rt> rts;
  int n, d, m, x, y;
  cin >> n >> d;

  rt aux;
  aux.ini(0, d, d, 0);
  rts.PB(aux);
  aux.ini(0, d, n - d, n);
  rts.PB(aux);
  aux.ini(d, 0, n, n - d);
  rts.PB(aux);
  aux.ini(n - d, n, n, n - d);
  rts.PB(aux);

  cin >> m;

  bool able;
  FOR(ab, 0, m){
    cin >> x >> y;
    able = 1;

    FOR(i, 0, 4){
      if(i & 1 and rts[i].f(x, y) > 0){
        able = false;
        break;
      }
      if(!(i & 1) and rts[i].f(x, y) < 0){
        able = false;
        break;
      }
    }

    cout << (able ? "YES\n" : "NO\n");
  }

  return 0;
} 