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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;


int main(){
  int cases, s, sum;
  ll n, ans, pot = 1000000000000000000, aux, num;
  bool pos;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> s;
    aux = pot, sum = num = 0;
    pos = false;
    
    FORI(i, 18, 0){
      if(pos){
        if(n/aux) sum += (n/aux)%10;
      }else{
        if(n/aux){
          sum += (n/aux)%10;
          
          if(sum >= s){
            pos = true;
            num = i + 1;
          }
        }
      }
      
      aux /= 10;
    }
    
    if(sum <= s) cout << 0 << "\n";
    else{
      aux = 1;
      FOR(i, 0, num) aux *= 10;
      
      num = aux - (n%aux);
      
      cout << num << "\n";
    }
  }
  
  return 0;
}
