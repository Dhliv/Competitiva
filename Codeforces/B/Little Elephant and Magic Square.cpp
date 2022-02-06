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

  vector<vector<int> > p(3, vector<int>(3));

  FOR(i, 0, 3){
    FOR(j, 0, 3) cin >> p[i][j];
  }

  int k = (p[0][1] + p[0][2] + p[1][0] + p[1][2] + p[2][0] + p[2][1])/2;
  p[0][0] = k - (p[0][1] + p[0][2]);
  p[1][1] = k - (p[1][0] + p[1][2]);
  p[2][2] = k - (p[2][0] + p[2][1]);

  FOR(i, 0, 3){
    FOR(j, 0, 3) cout << p[i][j] << " ";
    cout << "\n";
  }

  return 0;
}
