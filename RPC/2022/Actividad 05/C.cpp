#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s; getline(cin, s);

  int ans = 0, level = 0;
  deque<int> p;

  FOR(i, 0, s.size()){
    if(isspace(s[i])) continue;

    if(s[i] == '(') p.PB(1);
    else{
      level = 1;
      FORI(j, p.size() - 1, 0) p[j] = max(p[j], level++);
      ans += p.B();
      p.P_B();
    }
  }

  cout << ans << "\n";

  return 0;
}