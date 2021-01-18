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
  int cases, n, b;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    deque<int> q(n);
    set<pair<int, int> > areas;
    
    FOR(i, 0, n) cin >> q[i];
    
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        b = abs(q[i] - q[j]);
        areas.insert(MP(b/2, b%2));
      }
    }
    
    cout << areas.size() << "\n";
  }
  
  return 0;
}