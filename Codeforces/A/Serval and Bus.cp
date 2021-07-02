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
#define MAX 500005

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, t, x, d, mini, ans, ax;
  cin >> n >> t;
  
  mini = INF;
  FOR(i, 0, n){
    cin >> x >> d;
    
    if(x >= t and x < mini){
      mini = x;
      ans = i + 1;
    }else if(x < t){
      ax = (t - x)/d;
      if((t - x)%d) ax++;
      
      x = x + ax*d;
      if(x >= t and x < mini){
        mini = x;
        ans = i + 1;
      }
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}