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
  int cases, mod = (1 << 31) - 1, p;
  ll n, inv = 1789569706;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> n;
    n %= mod;
    cout << (((((n*(n + 1))%mod)*(n + 2))%mod)*inv)%mod << "\n";
  }
  
  return 0;
}