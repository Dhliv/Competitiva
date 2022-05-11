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

  int t, n, m, b; cin >> t;

  FOR(ab, 1, t + 1){
    cin >> n >> b;
    cout << "Practice #" << ab << ": " << n << " " << b << "\n";
    cin >> n;

    FOR(i, 0, n){
      cin >> m;

      while(b <= m) b*= 2;

      b -= m;
      cout << m << " " << b << "\n";
    }
  }

  return 0;
}