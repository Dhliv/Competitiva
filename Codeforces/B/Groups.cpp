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

bool ch(int i, int j, vector<vector<int> > &p, int &n){
  int x, y, xy, n2 = n/2, ax;
  x = y = xy = 0;

  FOR(k, 0, n){
    x += p[k][i];
    y += p[k][j];
    xy += p[k][i] & p[k][j];
  }

  x -= xy;
  y -= xy;
  if(x < n2){
    ax = min(n2 - x, xy);
    x += ax;
    xy -= ax;
  }

  if(y < n2){
    ax = min(n2 - y, xy);
    y += ax;
    xy -= ax;
  }

  if(x >= n2 and y >= n2) return true;
  return false;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    vector<vector<int> > p(n, vector<int> (5));

    FOR(i, 0, n){
      FOR(j, 0, 5) cin >> p[i][j];
    }

    bool able = false;
    FOR(i, 0, 4){
      for(int j = i + 1; j < 5; j++){
        if(ch(i, j, p, n)){
          able = true;
          break;
        }
      }
    }

    cout << (able ? "YES\n" : "NO\n");
  }
  
  return 0;
}