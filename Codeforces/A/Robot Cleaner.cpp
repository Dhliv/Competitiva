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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, a, b, x, y, sx, sy; cin >> t;
  int dx, dy, ans;

  FOR(ab, 0, t){
    cin >> n >> m >> b >> a >> sy >> sx;
    dx = dy = 1;
    ans = 0;

    while(true){
      if(a == sx or b == sy) break;

      if(a == m) dx *= -1;
      if(b == n) dy *= -1;

      a += dx;
      b += dy;
      ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
