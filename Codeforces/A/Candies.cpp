#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

ll dos(int a){
  ll ans = 0;
  FOR(i, 0, a){
    ans += pow(2, i);
  }
  return ans;
}

int main(){
  ll k, n, ans;
  int t;
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    
    FOR(i, 2, 63){
      k = dos(i);
      if(n % k == 0){
        ans = n/k;
        break;
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}