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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, x, ans, digit, cif;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> x;
    digit = x%10;
    
    ans = 10*(digit - 1);
    
    FOR(i, 1, 5){
      if(x/((int)(pow(10, i - 1))) != 0) ans += i;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}