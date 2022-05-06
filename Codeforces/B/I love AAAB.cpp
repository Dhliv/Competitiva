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
  
  int t, n, turns, x; cin >> t;
  string s;
  
  FOR(ab, 0, t) {
    cin >> s;
    bool able = true;
    stack<bool> as;
    
    FOR(i, 0, s.size()){
      if(s[i] == 'B'){
        if(as.size() == 0) {
          able = false;
          break;
        }
        
        as.pop();
      }else as.push(1);
    }
    
    if(s.size() == 1 or s[s.size() - 1] != 'B') able = false;
    
    if(able) cout << "YES\n";
    else cout << "NO\n";
  }
    
  return 0;
}