#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

  while(t--){
    cin >> n;
    vector<int> p(n);
    map<int, char> lemape;
    FOR(i, 0, n) cin >> p[i];

    string s; cin >> s;
    bool able = true;

    FOR(i, 0, s.size()){
      auto it = lemape.find(p[i]);

      if(it == lemape.end()){
        lemape.insert(MP(p[i], s[i]));
        continue;
      }

      if(it->s != s[i]){
        able = false;
        break;
      }
    }

    if(able) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}