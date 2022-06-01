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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void fill(int x, int y, vector<string> &d){
  d[y][x] = '#';
  int ax, ay;

  FOR(i, 0, 2){
    ay = y + dy[i];
    if(ay >= 0 and ay < d.size() and x < d[ay].size() and isspace(d[ay][x])) fill(x, ay, d);
  }

  FOR(i, 2, 4){
    ax = x + dx[i];
    if(ax >= 0 and ax < d[y].size() and isspace(d[y][ax])) fill(ax, y, d);
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, x, y; cin >> t;
  string s;
  getline(cin, s);

  FOR(ab, 0, t){
    vector<string> d;
    x = INF;
    y = -1;

    while(true){
      getline(cin, s);
      if(s[0] == '_') break;
      d.PB(s);

      if(x == INF){
        y++;
        FOR(i, 0, s.size()){
          if(s[i] == '*'){
            x = i;
            break;
          }
        }
      }
    }

    fill(x, y, d);

    FOR(i, 0, d.size()) cout << d[i] << "\n";
    cout << s << "\n";
  }

  return 0;
}