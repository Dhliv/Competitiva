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
 
const ld EPSILON = 0.000000001;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, m;
  string a, b;

  while(t--){
    cin >> n >> m >> a >> b;
    int cnt = 0;
    while(a.size() < b.size()){
      a += a;
      cnt++;
    }

    bool able = false;
    FOR(i, 0, 3){
      vector<int> z = z_function(b + "#" + a);
      FOR(j, b.size() + 1, z.size()){
        if(z[j] == b.size()){
          able = true;
          break;
        }
      }

      if(able) break;
      cnt++;
      a += a;
    }

    if(able) cout << cnt << "\n";
    else cout << "-1\n";
  }

  return 0;
}