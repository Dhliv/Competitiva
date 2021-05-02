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

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t, n, ans, x;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    deque<int> q(n);
    
    FOR(i, 0, n) cin >> q[i];
    
    sort(q.begin(), q.end());
    
    ans = 0;
    x = q[0];
    
    FOR(i, 1, n){
      if(q[i] > x){
        ans = n - i;
        break;
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}