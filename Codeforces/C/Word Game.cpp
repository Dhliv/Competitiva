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
  int n;

  while(t--){
    int ans, x;
    cin >> n;
    map<string, int> p;
    vector<vector<string> > q(3, vector<string> (n));
    FOR(i, 0, 3){
      FOR(j, 0, n){
        cin >> q[i][j];
        auto it = p.find(q[i][j]);
        if(it == p.end()) p.insert(MP(q[i][j], 1));
        else it->s++;
      }
    }

    FOR(i, 0, 3){
      ans = 0;
      FOR(j, 0, n){
        x = p[q[i][j]];
        if(x == 3) continue;
        if(x == 2) ans++;
        else ans += 3;
      }
      cout << ans << " ";
    }
    cout << "\n";
  }
 
  return 0;
}