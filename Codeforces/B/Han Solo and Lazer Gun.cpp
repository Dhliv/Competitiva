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

bool isOnLine(int x0, int y0, int x1, int y1, int x, int y){
  if(((y - y0)*(x1 - x0) - (y1 - y0)*(x - x0)) == 0) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x0, y0, x, y; cin >> n >> x0 >> y0;
  vector<pair<int, int> > p(n);
  vector<bool> s(n);

  FOR(i, 0, n){
    cin >> x >> y;
    p[i] = MP(x, y);
  }

  int sh = 0;

  FOR(i, 0, n){
    if(!s[i]){
      sh++;
      FOR(j, i + 1, n){
        if(s[j]) continue;
        s[j] = isOnLine(x0, y0, p[i].f, p[i].s, p[j].f, p[j].s);
      }
    }
  }

  cout << sh << "\n";

  return 0;
}
