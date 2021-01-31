#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
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
 
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll a, b, v, ax;
  while(cin >> a >> b){
    if(a == b and a == 0) break;
    v = b/2;
    ax = b%2;
    if(v%2) cout << a*-1 << (ax ? "i\n" : "\n");
    else cout << a << (ax ? "i\n" : "\n");
  }
  
  return 0;
}