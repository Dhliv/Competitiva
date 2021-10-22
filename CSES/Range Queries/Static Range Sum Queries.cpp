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
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, q, x, y;
  cin >> n >> q;

  vector<ll> sums(n + 1);

  FOR(i, 1, n + 1){
    cin >> x;
    sums[i] = sums[i - 1] + x;
  }

  FOR(i, 0, q){
    cin >> x >> y;
    cout << (sums[y] - sums[x - 1]) << "\n";
  }

  return 0;
}