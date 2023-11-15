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
#define MAX 5001

using namespace std;

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n;

  while(t--){
    cin >> n;
    vector<int> p(n); FOR(i, 0, n) cin >> p[i];
    if(n <= 2){
      cout << "YES\n";
      continue;
    }

    bool able = true;
    FOR(i, 1, 5) {
      int val = 1 << i;
      int upper = min(val << 1, n);

      FOR(j, val + 1, upper){
        if(p[j] < p[j - 1]){
          able = false;
          break;
        }
      }

      if(upper == n) break;
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}