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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, c, d, n; cin >> a >> b >> c >> d >> n;
  vector<int> p(n + 1);

  for(int i = a; i <= n; i += a) p[i] = 1;
  for(int i = b; i <= n; i += b) p[i] = 1;
  for(int i = c; i <= n; i += c) p[i] = 1;
  for(int i = d; i <= n; i += d) p[i] = 1;

  int ans = 0;
  FOR(i, 1, n + 1) ans += p[i];

  cout << ans << "\n";

  return 0;
}