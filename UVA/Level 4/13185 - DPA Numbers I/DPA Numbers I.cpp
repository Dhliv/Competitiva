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
  int cases;
  ll n, sum, res;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    sum = 1;
    res = sqrt(n);
    
    FOR(i, 2, res + 1){
      if(n%i == 0){
        sum += i;
        if(i != n/i) sum += n/i;
      }
    }
    
    if(sum > n) cout << "abundant\n";
    else if(sum == n) cout << "perfect\n";
    else cout << "deficient\n";
  }
  
  return 0;
}
