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
#define PI 3.14159265358979323846

using namespace std;

const double EPSILON = 0.0000001;

int board[9][9];
char dir[4] = {'U', 'D', 'R', 'L'};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int ord[48];

int ans;

bool onlyLeftAndRight(int &i, int &r, int &c){
  int nr, nc, ra, ca, rb, cb;
  int &lt = ord[i - 1];

  if(!board[r + dr[lt]][c + dc[lt]]) return false;
  if(lt < 2){ // up or down
    if(!board[r][c + 1] and !board[r][c - 1]) return true;
  }else{
    if(!board[r + 1][c] and !board[r - 1][c]) return true;
  }

  return false;
}

void f(int i, int r, int c){
  if(i == 48){
    ans++;
    return;
  }

  //cout << i << ": " << r << " & " << c << " -> " << s << "\n";
  if(r == 7 and c == 1) return;
  if(onlyLeftAndRight(i, r, c)) return;
  int nr, nc;

  if(ord[i] < 4){
    nr = r + dr[ord[i]];
    nc = c + dc[ord[i]];

    if(board[nr][nc]) return;
    board[nr][nc] = 1;
    f(i + 1, nr, nc);
    board[nr][nc] = 0;
  }else{
    FOR(j, 0, 4){
      nr = r + dr[j];
      nc = c + dc[j];

      if(board[nr][nc]) continue;
      board[nr][nc] = 1;
      ord[i] = j;
      f(i + 1, nr, nc);
      board[nr][nc] = 0;
      ord[i] = 4;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ans = 0;
  string s; cin >> s;

  FOR(i, 0, s.size()){
    ord[i] = 4;
    FOR(j, 0, 4){
      if(dir[j] == s[i]){
        ord[i] = j;
        break;
      }
    }
  }

  FOR(i, 0, 9){
    FOR(j, 0, 9){
      board[i][j] = 0;
    }
  }

  FOR(i, 0, 9){
    board[0][i] = 1;
    board[i][0] = 1;
    board[8][i] = 1;
    board[i][8] = 1;
  }

  board[1][1] = 1;

  if(s[0] == '?'){
    board[1][2] = 1;
    ord[0] = 2;
    f(1, 1, 2);
    board[1][2] = 0;
    board[2][1] = 1;
    ord[0] = 1;
    f(1, 2, 1);
    cout << ans << "\n";
  }else{
    if(s[0] == 'L' or s[0] == 'U') cout << "0\n";
    else{
      if(s[0] == 'R'){
        board[1][2] = 1;
        ord[0] = 2;
        f(1, 1, 2);
        cout << ans << "\n";
      }
      else{
        board[2][1] = 1;
        ord[0] = 1;
        f(1, 2, 1);
        cout << ans << "\n";
      }
    }
  }

  return 0;
}