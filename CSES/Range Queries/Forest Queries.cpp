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

  int n, q, x, y, x1, y1;
  cin >> n >> q;
  vector<string> d(n);
  vector<vector<int> > ps(n + 1, vector<int> (n + 1));

  FOR(i, 0, n) cin >> d[i];

  ps[1][1] = (d[0][0] == '*' ? 1 : 0);

  FOR(i, 2, n + 1){
    ps[i][1] = ps[i - 1][1] + (d[i - 1][0] == '*' ? 1 : 0);
    ps[1][i] = ps[1][i - 1] + (d[0][i - 1] == '*' ? 1 : 0);
  }

  FOR(i, 2, n + 1){
    FOR(j, 2, n + 1){
      ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + (d[i - 1][j - 1] == '*' ? 1 : 0);
    }
  }

  FOR(i, 0, q){
    cin >> y >> x >> y1 >> x1;
    if(y > y1 or x > x1){
      swap(y1, y);
      swap(x1, x);
    }

    cout << (ps[y1][x1] - ps[y - 1][x1] - ps[y1][x - 1] + ps[y - 1][x - 1]) << "\n";
  }
  
  return 0;
}