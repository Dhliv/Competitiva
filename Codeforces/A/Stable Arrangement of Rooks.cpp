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

  int t, n, k, l; cin >> t;

  FOR(ab, 0, t){
    cin >> n >> k;
    vector<string> d(n);
    string s = "";
    FOR(i, 0, n) s.PB('.');
    FOR(i, 0, n) d[i] = s;

    l = k;

    for(int i = 0; i < n and l > 0; i += 2){
      d[i][i] = 'R';
      l--;
    }

    if(l) cout << "-1\n";
    else FOR(i, 0, n) cout << d[i] << "\n";
  }

  return 0;
}
