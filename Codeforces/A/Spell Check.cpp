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

  int t, n; cin >> t;
  string s;
  vector<int> h(255), cp;

  h['T'] = 1;
  h['i'] = 1;
  h['m'] = 1;
  h['u'] = 1;
  h['r'] = 1;

  while(t--){
    cin >> n >> s;

    if(n != 5){
      cout << "No\n";
      continue;
    }

    cp = h;
    FOR(i, 0, n) cp[s[i]]--;

    bool able = true;
    FOR(i, 0, cp.size()){
      if(cp[i] != 0){
        able = false;
        break;
      }
    }

    cout << (able ? "Yes" : "No") << "\n";
  }
 
  return 0;
}