#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

  int n; cin >> n;
  vector<int> A(n + 1), B(n + 1), C(n + 1);
  FOR(i, 1, n + 1) cin >> A[i];
  FOR(i, 1, n + 1) cin >> B[i];
  FOR(i, 1, n + 1) cin >> C[i];

  ll ans = 0;
  map<int, ll> p;

  FOR(i, 1, n + 1){
    auto it = p.find(B[C[i]]);
    if(it != p.end()) it->s++;
    else p.insert(MP(B[C[i]], 1));
  }

  FOR(i, 1, n + 1){
    auto it = p.find(A[i]);
    if(it != p.end()) ans += it->s;
  }

  cout << ans << "\n";

  return 0;
}
