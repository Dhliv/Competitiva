#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<int> p(n); FOR(i, 0, n) cin >> p[i];
  sort(p.begin(), p.end());

  int ans = 0;
  for(int i = 1; i < n; i += 2){
    ans += p[i] - p[i - 1];
  }

  cout << ans << "\n";

  return 0;
}