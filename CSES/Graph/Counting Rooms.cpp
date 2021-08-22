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
#define MAX 1000
 
using namespace std;

vector<vector<bool> > g(MAX, vector<bool> (MAX));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

void l(int i, int j){
  g[i][j] = 0;

  int x, y;
  FOR(k, 0, 4){
    x = i + dy[k];
    y = j + dx[k];

    if(0 <= x and x < n and 0 <= y and y < m and g[x][y]) l(x, y);
  }

  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int ans = 0;
  cin >> n >> m;
  string s;

  FOR(i, 0, n){
    cin >> s;
    FOR(j, 0, m){
      g[i][j] = (s[j] == '.' ? 1 : 0);
    }
  }

  FOR(i, 0, n){
    FOR(j, 0, m){
      if(g[i][j]){
        l(i, j);
        ans++;
      }
    }
  }

  cout << ans << "\n";
  
  return 0;
}
