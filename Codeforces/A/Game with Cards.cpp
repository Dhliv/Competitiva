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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n, m, a, b, x; cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    a = b = 0;
    FOR(i, 0, n){
      cin >> x;
      a = max(a, x);
    }
    cin >> m;
    FOR(i, 0, m){
      cin >> x;
      b = max(b, x);
    }

    if(a == b) cout << "Alice\nBob\n";
    else if(a > b) cout << "Alice\nAlice\n";
    else cout << "Bob\nBob\n";
  }

  return 0;
}