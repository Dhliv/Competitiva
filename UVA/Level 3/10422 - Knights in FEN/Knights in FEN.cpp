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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int n = 5, mini;
vector<string> sol{"11111", "01111", "00 11", "00001", "00000"};
vector<int> dy{2, 2, 1, 1, -1, -1, -2, -2};
vector<int> dx{-1, 1, -2, 2, -2, 2, -1, 1};

void f(vector<string> &board, int i, int j, int moves){
  if(sol == board){
    mini = min(mini, moves);
    return;
  }
  if(moves == 10) return;
  
  int ni, nj;
  
  FOR(k, 0, 8){
    if(i + dy[k] < n and i + dy[k] >= 0){
      if(j + dx[k] < n and j + dx[k] >= 0){
        ni = i + dy[k];
        nj = j + dx[k];
        board[i][j] = board[ni][nj];
        board[ni][nj] = ' ';
        f(board, ni, nj, moves + 1);
        board[ni][nj] = board[i][j];
        board[i][j] = ' ';
      }
    }
  }
}

int main(){
  int cases;
  string ent;
  cin >> cases;
  getline(cin, ent);
  
  FOR(a, 0, cases){
    vector<string> board(n);
    
    FOR(i, 0, n) getline(cin, board[i]);
    
    mini = INF;
    FOR(i, 0, n){
      FOR(j, 0, n){
        if(isspace(board[i][j])){
          f(board, i, j, 0);
          break;
        }
      }
    }
    
    if(mini == INF) cout << "Unsolvable in less than 11 move(s).\n";
    else cout << "Solvable in " << mini << " move(s).\n";
  }
  
  return 0;
}
