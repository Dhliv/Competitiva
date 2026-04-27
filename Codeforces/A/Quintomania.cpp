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

  int t; cin >> t;
  FOR(ab, 0, t) {
    int n; cin >> n;
    int l; cin >> l;

    bool ans = true;
    FOR(i, 1, n) {
      int l2; cin >> l2;
      if(abs(l2 - l) != 7 and abs(l2 - l) != 5) ans = false;
      l = l2;
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
  
  return 0;
}