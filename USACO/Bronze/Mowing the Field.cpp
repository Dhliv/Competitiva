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

  ifstream cin;
  cin.open("mowing.in");
  ofstream cout("mowing.out");

  int n; cin >> n;
  int tx, t = 0, x = 0, y = 0, vecs, dx, dy;
  char dir;
  map<pair<int, int>, int> pos;
  pos.insert(MP(MP(x, y), 0));
  int ans = INF;

  FOR(i, 0, n){
    cin >> dir >> vecs;

    dx = dy = 0;
    if(dir == 'N') dy = -1;
    else if(dir == 'S') dy = 1;
    else if(dir == 'E') dx = 1;
    else dx = -1;

    FOR(j, 0, vecs){
      x += dx;
      y += dy;
      t++;

      if(pos.count(MP(x, y))){
        ans = min(ans, t - pos[MP(x, y)]);
        pos[MP(x, y)] = t;
      }else pos.insert(MP(MP(x, y), t));
    }
  }

  cout << (ans == INF ? -1 : ans) << "\n";
  
  return 0;
}
