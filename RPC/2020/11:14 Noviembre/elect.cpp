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
  int n, v1, v2, x, y, e1, e2, e;
  e1 = e2 = v1 = v2 = 0;
  
  cin >> n;
  
  FOR(i, 0, n){
    cin >> e >> x >> y;
    v1 += x;
    v2 += y;
    if(x > y) e1 += e;
    else e2 += e;
  }
  
  if(v1 > v2 and e1 > e2) cout << "1\n";
  else if(v2 > v1 and e2 > e1) cout << "2\n";
  else cout << "0\n";
  
  return 0;
}