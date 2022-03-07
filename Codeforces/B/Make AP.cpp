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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, a, b, c; cin >> t;

  FOR(ab, 0, t){
    cin >> a >> b >> c;

    if((2*b - a) % c == 0 and (2*b - a)/c > 0) cout << "yes\n";
    else if((2*b - c) % a == 0 and (2*b - c)/a > 0) cout << "yes\n";
    else if((a + c) % (2*b) == 0 and (a + c)/(2*b) > 0) cout << "yes\n";
    else cout << "NO\n";
  }
  
  return 0;
}
