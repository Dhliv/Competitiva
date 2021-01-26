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
  
  int t;
  ll a;
  bool able;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a;
    able = false;
    if(a & (1 << 0)) cout << "YES\n";
    else{
      while(a > 2){
        a /= 2;
        if(a%2){
          able = true;
          break;
        }
      }
      
      if(able) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  
  return 0;
}