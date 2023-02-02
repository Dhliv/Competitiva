#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

  while(t--){
    int n; cin >> n;
    string s, ax; cin >> s;
    map<string, int> pos;

    bool able = false;
    FOR(i, 0, n - 1){
      ax = s.substr(i, 2);

      auto it = pos.find(ax);
      if(it != pos.end()){
        if(it->s < i - 1){
          able = true;
          break;
        }
      }else pos.insert(MP(ax, i));
    }

    cout << (able ? "YES" : "NO") << "\n";
  }
 
  return 0;
}