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
  int cases, a, b, mod;
  cin >> cases;
  
  FOR(c, 0, cases){
    cin >> a >> b;
    mod = a%b;
    if(mod){
      cout << (b - mod) << "\n";
    }else cout << 0 << "\n";
  }

  return 0;
}