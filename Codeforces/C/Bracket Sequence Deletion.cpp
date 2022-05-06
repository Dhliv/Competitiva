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
 
ll mod = 1000000007;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t, st, n, ops, left, l; cin >> t;
  ll forward, backward, pact;
  string s;
 
  FOR(ab, 0, t){
    cin >> n >> s;
    left = n;
    forward = backward = ops = st = l = 0;
    pact = 1;
 
    FOR(i, 0, n){
      if(s[i] == '('){
        st++;
        forward = (forward + pact)%mod;
        backward = (2*backward + 1)%mod;
      }else{
        st--;
        backward = (2*backward)%mod;
      }
 
      if(st < 0) st = -n;
      //cout << st << " " << forward << " " << backward << " " << l << "\n";
 
      l++;
      pact = (2*pact)%mod;
 
      if(st == 0 or (forward == backward and l > 1)) {
        left -= l;
        l = 0;
        st = forward = backward = 0;
        ops++;
        pact = 1;
      }
    }
 
    cout << ops << " " << left << "\n";
  }
 
  return 0;
}