#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
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

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n = 8;

  while(t--){
    vector<string> board(n);
    FOR(i, 0, n) cin >> board[i];

    bool found = false;
    string word = "";
    FOR(i, 0, n){
      if(found) break;
      FOR(j, 0, n){
        if(board[i][j] != '.'){
          found = true;
          int k = i;
          while(k < n and board[k][j] != '.'){
            word.PB(board[k][j]);
            k++;
          }
          break;
        }
      }
    }

    cout << word << "\n";
  }
 
  return 0;
}