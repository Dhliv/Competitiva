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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;


int main(){
  int cases, n;
  ll ans, m;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    ans = 0;
    
    while(n > 9){
      m = n/10;
      ans += m*10;
      n -= m*9;
    }
    
    if(n >= 1) ans += n;
    
    cout << ans << "\n";
  }
  
  return 0;
}
