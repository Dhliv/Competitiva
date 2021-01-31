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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

set<pair<vector<string>, int> > ans, act, nes;
vector<int> s;
int n, k;

bool poss(int i, int j, vector<vector<int > > &aux, int k, int dir){
  //. = 2, O = 1, X = 0.
  
  if(dir == 0){
    FOR(a, j + 1, j + k) if(aux[i][a] == 0) return false;
  }
  else{
    FOR(a, i + 1, i + k) if(aux[a][j] == 0) return false;
  }
  
  return true;
}

ll ini(int bar, vector<vector<int> > &grid){
  int pos, x;
  ll ans = 0;
  
  if(bar == k){
    FOR(i, 0, n){
      FOR(j, 0, n){
        if(grid[i][j] == 1) return 0;
      }
    }
    return 1;
  }
  x = s[bar];
  vector<int> data(n);
  
  FOR(a, 0, n){
    FOR(b, 0, n){
      if(grid[a][b]){
        if(b + x <= n and poss(a, b, grid, x, 0)){
          FOR(c, b, b + x){
            data[c] = grid[a][c];
            grid[a][c] = 0;
          }
          ans += ini(bar + 1, grid);
          FOR(c, b, b + x) grid[a][c] = data[c];
        }
        if(a + x <= n and poss(a, b, grid, x, 1) and x != 1){
          FOR(c, a, a + x){
            data[c] = grid[c][b];
            grid[c][b] = 0;
          }
          ans += ini(bar + 1, grid);
          FOR(c, a, a + x) grid[c][b] = data[c];
        }
      }
    }
  }
  
  //cout << ans << " ";
  return ans;
}

int main(){
  cin >> n >> k;
  deque<pair<int, int> > p;
  s.resize(k);
  string ent;
  vector<vector<int> > grid(n, vector<int> (n)); //char and original or artificial
  
  FOR(i, 0, n){ //. = 2, O = 1, X = 0.
    cin >> ent;
    FOR(j, 0, n){
      if(ent[j] == '.') grid[i][j] = 2;
      else if(ent[j] == 'O') grid[i][j] = 1;
      else grid[i][j] = 0;
    }
  }
  
  FOR(i, 0, k) cin >> s[i];
  
  cout << ini(0, grid) << "\n";
  
  return 0;
}