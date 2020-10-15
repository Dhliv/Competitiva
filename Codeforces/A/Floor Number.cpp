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
  int cases, n, k, ans, p;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> k;
    if(n <= 2) cout << "1\n";
    else{
      ans = (int)ceil((n*1.0 - 2)/k);
      p = ans - 1;
      if(n <= p*k + 2) cout << p + 1 << "\n";
      else cout << ans + 1 << "\n";
    }
  }
  
  return 0;
}