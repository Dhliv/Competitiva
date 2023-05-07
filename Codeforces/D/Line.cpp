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

  int t; cin >> t;
  int n;
  ll ans, sum, l, r;
  string s;

  while(t--){
    cin >> n;
    cin >> s;
    ans = sum = 0;
    FOR(i, 0, n){
      if(s[i] == 'L') sum += i;
      else sum += (n - i - 1);
    }

    ans = sum;
    deque<ll> q;
    FOR(i, 0, n){
      l = i;
      r = n - i - 1;

      if(l > r and s[i] == 'R') q.PB(l - r);
      else if(r > l and s[i] == 'L') q.PB(r - l);
      else q.PB(0);
    }

    sort(q.begin(), q.end());

    ans = sum;
    FORI(i, n - 1, 0){
      ans += q[i];
      cout << ans << " ";
    }
    cout << "\n";
  }
 
  return 0;
}