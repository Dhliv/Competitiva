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
  int n, cases, d, elem, sum;
  bool able;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    deque<int> q(n);
    set<int> on;
    sum = 0;
    
    FOR(i, 0, n){
      cin >> q[i];
      sum += q[i];
      on.insert(q[i]);
    }
    q.PB(0);
    
    if(on.size() == 1) cout << "0\n";
    else{
      FOR(k, 0, n){
        d = sum/(n - k);
        if(sum%(n - k)) continue;
        
        able = true;
        elem = 0;
        FOR(i, 0, n + 1){
          if(elem == d){
            elem = 0;
            i--;
          }else if(elem > d){
            able = false;
            break;
          }else elem += q[i];
        }
        
        if(able){
          cout << k << "\n";
          break;
        }
      }
    }
  }
  
  return 0;
}