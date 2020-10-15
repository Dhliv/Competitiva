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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int n, m;

void elim(vector<string> &tab, int i, int j){
  tab[i][j] = '*';
  
  if(i+1 < n and tab[i+1][j] == '@')
    elim(tab, i+1, j);
  if(i+1 < n and j+1 < m and tab[i+1][j+1] == '@')
    elim(tab, i+1, j+1);
  if(i+1 < n and j-1 >= 0 and tab[i+1][j-1] == '@')
    elim(tab, i+1, j-1);
  if(j-1 >= 0 and tab[i][j-1] == '@')
    elim(tab, i, j-1);
  if(j+1 < m and tab[i][j+1] == '@')
    elim(tab, i, j+1);
  if(i-1 >= 0 and tab[i-1][j] == '@')
    elim(tab, i-1, j);
  if(i-1 >= 0 and j+1 < m and tab[i-1][j+1] == '@')
    elim(tab, i-1, j+1);
  if(i-1 >= 0 and j-1 >= 0 and tab[i-1][j-1] == '@')
    elim(tab, i-1, j-1);
}

int main() {
  int oils;
  
  while(cin >> n >> m, n+m){
    vector<string> tab(n);
    oils = 0;
    
    FOR(i, 0, n)
      cin >> tab[i];
      
    FOR(i, 0, n){
      FOR(j, 0, m){
        if(tab[i][j] == '@'){
          oils++;
          elim(tab, i, j);
        }
      }
    }
    
    cout << oils << "\n";
  }

  return 0;
}