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
  int cases, h, w, n;
  ll res;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> h >> w >> n;
    res = 1;
    
    while(!(h%2)){
      res *= 2;
      h /= 2;
    }
    
    while(!(w%2)){
      res *= 2;
      w /= 2;
    }
    
    if(res >= n) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}