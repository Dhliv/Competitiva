#include <bits/stdc++.h>
#define INF INT_MAX
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
#define MAX 300

using namespace std;

const ld EPSILON = 0.0000001;
int sq;

struct edge{
  int x, y, moves, val;

  edge(){moves = 0;}
  edge(int x, int y, int moves){
    this->x = x;
    this->y = y;
    this->moves = moves;
    val = x*x + y*y;
  }

  bool isValid(){
    return val <= sq;
  }

  bool isAnswer(){
    return val == sq;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, s, t, x, y; cin >> t;
  edge e;

  while(t--){
    cin >> n >> s;
    vector<edge> coins(n); FOR(i, 0, n) cin >> coins[i].x >> coins[i].y;
    vector<vector<int> > dp(s + 1, vector<int> (s + 1));
    sq = s*s;

    int ans = -1;
    deque<edge> q, vacio;
    q.PB(edge(0, 0, 0));
    while(!q.empty()){
      e = q.F(); q.P_F();

      for(const edge &ee: coins){
        edge ax(e.x + ee.x, e.y + ee.y, e.moves + 1);
        if(!ax.isValid()) continue;
        if(dp[ax.x][ax.y]) continue;
        if(ax.isAnswer()){
          q.swap(vacio);
          ans = ax.moves;
          break;
        }

        dp[ax.x][ax.y] = 1;
        q.PB(ax);
      }
    }

    if(ans == -1) cout << "not possible\n";
    else cout << ans << "\n";
  }
 
  return 0;
}