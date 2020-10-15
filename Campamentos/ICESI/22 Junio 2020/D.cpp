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
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  ll cases, a, b, veces, ans;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> a >> b;
    veces = ans = 0;
    
    if(a > b){
      while(a > b){
        if(a%2) break;
        a /= 2;
        veces++;
      }
      if(a != b)
        cout << -1 << "\n";
      else{
        ans += veces/3;
        veces = veces%3;
        ans += veces/2;
        ans += veces%2;
        cout << ans << "\n";
      }
    }else if(a < b){
      while(a < b){
        a *= 2;
        veces++;
      }
      
      if(a != b)
        cout << -1 << "\n";
      else{
        ans += veces/3;
        veces = veces%3;
        ans += veces/2;
        ans += veces%2;
        cout << ans << "\n";
      }
    }else
      cout << 0 << "\n";
  }
  
  return 0;
}