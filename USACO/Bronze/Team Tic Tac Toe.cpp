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
  cin.open("tttt.in");
  ofstream cout("tttt.out");

  vector<string> board(3);
  FOR(i, 0, 3) cin >> board[i];

  vector<set<int> > sols(8);

  FOR(i, 0, 3){
    FOR(j, 0, 3){
      sols[i].insert(board[i][j] - 'A');
      sols[i + 3].insert(board[j][i] - 'A');
    }

    sols[6].insert(board[i][i] - 'A');
    sols[7].insert(board[2 - i][i] - 'A');
  }

  int u = 0, d = 0;
  FOR(i, 0, 26){
    FOR(j, i + 1, 26){
      FOR(k, 0, sols.size()){
        if(sols[k].count(i) and sols[k].count(j) and sols[k].size() == 2){
          d++;
          break;
        }
      }
    }

    FOR(j, 0, sols.size()){
      if(sols[j].count(i) and sols[j].size() == 1){
        u++;
        break;
      }
    }
  }

  cout << u << "\n" << d << "\n";
  
  return 0;
}
