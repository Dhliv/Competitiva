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

struct step{
  int x, y, steps, hungry;

  void operator() (int c, int d, int e, int f){
    x = c;
    y = d;
    steps = e;
    hungry = f;
  }
};

bool operator< (const step &a, const step &b){
  if(a.steps > b.steps) return true;
  if(a.steps == b.steps) return a.hungry > b.hungry;
  return false;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int r, c, f, s, x, y, nh, ns; cin >> r >> c >> f >> s;
  vector<vector<int> > d(r, vector<int> (c));
  vector<vector<vector<int> > > seen(r, vector<vector<int> > (c, vector<int> (f, INF))), v(r, vector<vector<int> > (c, vector<int> (f)));

  d[r - 1][c - 1] = 1;
  FOR(i, 0, s){
    cin >> x >> y;
    x--; y--;
    d[x][y] = 1; // it's a shop;
  }

  priority_queue<step> pq;
  step ax, toadd;
  ax(0, 0, 0, 0);
  pq.push(ax);

  FOR(i, 0, f) seen[0][0][i] = 0;

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  while(!pq.empty()){
    ax = pq.top();
    pq.pop();

    if(v[ax.y][ax.x][ax.hungry]) continue;
    v[ax.y][ax.x][ax.hungry] = 1;
    //cout << ax.y << " " << ax.x << ": " << ax.steps << " " << ax.hungry << endl;

    FOR(i, 0, 4){
      x = ax.x + dx[i];
      y = ax.y + dy[i];
      nh = ax.hungry + 1;

      if(y >= 0 and y < r and x >= 0 and x < c){
        if(d[y][x] == 1) nh = 0;
        if(nh < f and !v[y][x][nh]){
          ns = 1 + seen[ax.y][ax.x][ax.hungry];
          if(seen[y][x][nh] > ns){
            seen[y][x][nh] = ns;
            toadd(x, y, ns, nh);
            pq.push(toadd);
          }
        }
      }
    }
  }

  int ans = INF;
  FOR(i, 0, f) ans = min(ans, seen[r - 1][c - 1][i]);

  cout << ans << "\n";

  return 0;
}