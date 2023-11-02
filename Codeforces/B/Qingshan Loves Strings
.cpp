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

  int t; cin >> t;
  int n, m;

  while(t--){
    cin >> n >> m;
    string s, t; cin >> s >> t;
    bool able = true;

    FOR(i, 1, n){
      if(s[i] == s[i - 1]){
        able = false;
        break;
      }
    }

    if(able){
      cout << "YES\n";
      continue;
    }

    able = true;
    FOR(i, 1, m){
      if(t[i] == t[i - 1]){
        able = false;
        break;
      }
    }

    if(!able){
      cout << "NO\n";
      continue;
    }

    FOR(i, 1, n){
      if(s[i] != s[i - 1]) continue;
      if(s[i - 1] == t[0] or s[i] == t[m - 1]){
        able = false;
        break;
      }
    }

    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}