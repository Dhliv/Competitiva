#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF -1000000000
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
  set<int> h;
  ll fib[10001], mod = ((1 << 31) - 1);
  fib[0] = 0;
  fib[1] = 1;
  h.insert(0);
  h.insert(1);
  FOR(i, 2, 10001){
    fib[i] = (fib[i - 1] + fib[i - 2])%mod;
    h.insert(fib[i]);
  }
  
  int cases, n;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    if(h.find(n) != h.end()) cout << "YES\n";
    else cout << "NO\n";
  }
  
  
  return 0;
}