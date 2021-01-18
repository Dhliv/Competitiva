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
  int b, r, sum, max, iniMax, finMax, ini, fin, cy, cicloMax;
  bool able;
  cin >> b;
  
  FOR(a, 0, b){
    cin >> r;
    deque<int> q(r);
    
    able = false;
    max = sum = iniMax = finMax = cicloMax = 0;
    
    FOR(i, 0, r - 1){
      cin >> q[i];
      if(q[i] > 0) able = true;
    }
    q[r - 1] = MINF;
    
    if(able){
      sum = ini = fin = 0;
      FOR(i, 0, r){
        sum += q[i];
        
        if(sum > max){
          max = sum;
          iniMax = ini;
          finMax = i;
          cicloMax = i - ini;
        }else if(sum == max){
          cy = i - ini;
          if(cy > cicloMax){
            iniMax = ini;
            finMax = i;
            cicloMax = cy;
          }
        }
        
        if(sum < 0){
          ini = i + 1;
          sum = 0;
        }
      }
      
      cout << "The nicest part of route " << a + 1 << " is between stops " << iniMax + 1 << " and " << finMax + 2 << "\n";
    }else cout << "Route " << a + 1 << " has no nice parts\n";
  }
  
  return 0;
}