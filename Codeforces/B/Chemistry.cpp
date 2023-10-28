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
  string s;
  int n, k;

  while(t--){
    cin >> n >> k >> s;
    int need = n - k;
    vector<int> hs(255);
    FOR(i, 0, s.size()) hs[s[i]]++;

    int p = 0, ip = 0;
    FOR(i, 0, 255){
      if(hs[i] == 0) continue;
      if(hs[i] & 1) ip++;
      else p++;
    }

    bool able = true;
    while(k and ip) {
      if(ip == 1 and need & 1) break;
      ip--;
      k--;
    }

    if(ip > 1) able = false;
    if(k & 1 and need%2 == 0) able = false;
    cout << (able ? "YES" : "NO") << "\n";
  }

  return 0;
}