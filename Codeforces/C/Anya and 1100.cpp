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
 
using namespace std;
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  FOR(ab, 0, t) {
    string s; cin >> s;
    int cnt = 0;

    FOR(i, 0, s.size() - 3) {
      if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') cnt++;
    }

    int q; cin >> q;
    FOR(i, 0, q) {
      int pos, b; cin >> pos >> b;
      pos--;

      FOR(j, 0, 4) {
        int p1 = pos - j + 3;
        if(p1 >= s.size() or pos - j < 0) continue;
        if(s[p1 - 3] == '1' and s[p1 - 2] == '1' and s[p1 - 1] == '0' and s[p1] == '0') cnt--;
      }

      s[pos] = b + '0';
      FOR(j, 0, 4) {
        int p1 = pos - j + 3;
        if(p1 >= s.size() or pos - j < 0) continue;
        if(s[p1 - 3] == '1' and s[p1 - 2] == '1' and s[p1 - 1] == '0' and s[p1] == '0') cnt++;
      }

      cout << (cnt ? "YES" : "NO") << "\n";
    }
  }
  
  return 0;
}