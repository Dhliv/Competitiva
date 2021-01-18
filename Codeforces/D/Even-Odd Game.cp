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
  ll cases, n, t, a, b;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    vector<int> q(n);
    
    FOR(i, 0, n) cin >> q[i];
    
    sort(q.begin(), q.end());
    
    t = a = b = 0;
    
    FORI(i, n - 1, 0){
      if(t){
        if(q[i]%2) b += q[i];
      }else{
        if(q[i]%2 == 0) a += q[i];
      }
      t = (t + 1)%2;
    }
    
    if(a == b) cout << "Tie\n";
    else if(a > b) cout << "Alice\n";
    else cout << "Bob\n";
  }
  
  return 0;
}