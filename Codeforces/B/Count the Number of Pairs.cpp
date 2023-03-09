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

  int t, n, k, ans; cin >> t;

  while(t--){
    cin >> n >> k;
    vector<int> up(255), low(255);
    string s; cin >> s;

    FOR(i, 0, n){
      if(isupper(s[i])) up[tolower(s[i])]++;
      else low[s[i]]++;
    }

    ans = 0;
    int left = 0, x;
    FOR(i, 'a', 'z' + 1){
      x = min(up[i], low[i]);
      ans += x;
      left += (max(up[i], low[i]) - x)/2;
    }

    cout << ans + min(k, left) << "\n";
  }
 
  return 0;
}