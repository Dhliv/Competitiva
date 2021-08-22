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
#define MAX 5010
#define DS LLONG_MAX
 
using namespace std;
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int x, ans = 0;

  FOR(i, 0, 5){
    FOR(j, 0, 5){
      cin >> x;
      if(x == 1){
        ans += abs(i - 2);
        ans += abs(j - 2);
        cout << ans << "\n";
        return 0;
      }
    }
  }
  
  return 0;
}
