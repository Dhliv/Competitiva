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
 
ll get(int a, int b) {
  ll ans = 1, maxi, mini;
  ll p = 2;
 
  if(b == a or b == 0) return 1; 
 
  if(a - b > b){
    maxi = a - b;
    mini = b;
  }else{
    maxi = b;
    mini = a - b;
  }
 
  FORI(i, a, maxi + 1) {
    ans *= i;
    if(p > mini) continue;
    if(ans % p == 0) ans /= p++;
  }
 
  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t; cin >> t;
  string s, s2;
  ll ans;
 
  FOR(aab, 0, t){
    cin >> s >> s2;
    vector<int> p(26);
    FOR(i, 0, s2.size()) {
      p[s2[i] - 'a']++;
    }
 
    if(p[0] and s2.size() == 1) cout << "1\n";
    else if(p[0] and s2.size() > 1) cout << "-1\n";
    else{
      ans = 0;
 
      FOR(i, 0, s.size() + 1) ans += get(s.size(), i);
 
      cout << ans << "\n";
    }
  }
  
  return 0;
}