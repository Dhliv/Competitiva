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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, win, x, y;
  string s;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> s;
    win = 0;
    deque<int> winners;

    FOR(i, 0, n){
      if(s[i] == '2'){
        win++;
        winners.PB(i);
      }
    }

    if(win == 1 or win == 2) cout << "NO\n";
    else{
      cout << "YES\n";
      vector<vector<char> > m(n, vector<char> (n));

      FOR(i, 0, n){
        m[i][i] = 'X';
        FOR(j, 0, n){
          if(j == i) continue;
          m[i][j] = '=';
        }
      }

      winners.PB(winners.F());
      FOR(i, 0, winners.size() - 1){
        x = winners[i];
        y = winners[i + 1];
        m[x][y] = '+';
        m[y][x] = '-';
      }

      FOR(i, 0, n){
        FOR(j, 0, n){
          cout << m[i][j];
        }
        cout << "\n";
      }
    }
  }
 
  return 0;
} 