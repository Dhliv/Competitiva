#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, ent, mil, jui, aux, lista;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> lista;
    cout << "Case " << a+1 << ": ";
    mil = 0;
    jui = 0;
    
    FOR(i, 0, lista){
      cin >> ent;
      aux = (ent/30) + 1;
      mil += 10*aux;
      aux = (ent/60) + 1;
      jui += 15*aux;
    }
    
    if(jui < mil)
      cout << "Juice " << jui << "\n";
    else if(mil < jui)
      cout << "Mile " << mil << "\n";
    else
      cout << "Mile Juice " << jui << "\n";
  }
  
  return 0;
}