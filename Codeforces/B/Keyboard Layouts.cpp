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

const ld EPSILON = 0.0000000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a, b, c; cin >> a >> b >> c;
  string ans = c;
  vector<int> hs(255);
  FOR(i, 0, a.size()) hs[a[i]] = b[i];
  FOR(i, 0, 10) hs[i + '0'] = i + '0';

  FOR(i, 0, c.size()){
    char k = tolower(c[i]);
    ans[i] = hs[k];
    if(c[i] >= 'A' and c[i] <= 'Z') ans[i] = toupper(ans[i]);
  }

  cout << ans << "\n";

  return 0;
}