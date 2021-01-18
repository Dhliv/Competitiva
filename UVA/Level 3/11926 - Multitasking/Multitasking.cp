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
  int n, m, a, b, l = 1000001, rep, cont, maxi;
  bool able;
  
  while(cin >> n >> m, n + m){
    bitset<1000001> p;
    able = true;
    
    FOR(i, 0, n){
      cin >> a >> b;
      
      if(able){
        for(int j = a; j < b and j < l; j++){
          if(p.test(j)){
            able = false;
            break;
          }
          p.set(j, 1);
        }
      }
    }
    
    FOR(i, 0, m){
      cin >> a >> b >> rep;
      
      if(able){
        cont = 0;
        for(int j = b; j < l; j += rep){
          for(int k = a + cont*rep; k < j; k++){
            if(p.test(k)){
              able = false;
              break;
            }
            p.set(k, 1);
          }
          cont++;
        }
      }
    }
    
    if(able) cout << "NO CONFLICT\n";
    else cout << "CONFLICT\n";
  }
  
  return 0;
}