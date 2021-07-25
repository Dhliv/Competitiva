#include <bits/stdc++.h>
#define INF 100000
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

int coins[10];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  coins[0] = 1;
  FOR(i, 1, 10) coins[i] = coins[i - 1]*(i + 1);
  
  int p, ans = 0; cin >> p;
  
  FORI(i, 9, 0){
    ans += p/coins[i];
    p %= coins[i];
  }
  
  cout << ans << "\n";

  return 0;
}