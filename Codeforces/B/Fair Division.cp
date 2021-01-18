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
  int cases, n, a, p, ip;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    p = ip = 0;
    
    FOR(i, 0, n){
      cin >> a;
      if(a%2) ip++;
      else p++;
    }
    
    if(ip%2) cout << "NO\n";
    else{
      if(p%2 == 0 or ip > 0) cout << "YES\n";
      else cout << "NO\n";
      
    }
  }
  
  return 0;
}