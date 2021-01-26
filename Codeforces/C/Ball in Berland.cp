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
  int t, a, b, k, ax;
  ll ans;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> a >> b >> k;
    vector<int> A(k), B(k), bo(a + 1), gi(b + 1);
    FOR(i, 0, k){
      cin >> A[i];
      bo[A[i]]++;
    }
    
    FOR(i, 0, k){
      cin >> B[i];
      gi[B[i]]++;
    }
    
    ans = 0;
    ax = k;
    FOR(i, 0, k){
      ans += (ax - bo[A[i]] - gi[B[i]] + 1);
      bo[A[i]]--;
      gi[B[i]]--;
      ax--;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}