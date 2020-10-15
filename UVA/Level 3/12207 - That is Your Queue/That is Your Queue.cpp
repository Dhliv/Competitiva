#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
 
using namespace std;

typedef deque<int> DQ;
typedef map<ll,int> mapa;

int main()
{
  ll pacientes, querys, datum, cases = 1;
  string aux;
  DQ fila;
  
  while(cin >> pacientes >> querys, pacientes){
    cout << "Case " << cases << ":\n";
    
    if(querys <= pacientes){
      FOR(i, 0, querys)
        fila.PB(i%pacientes + 1);
    }else{
      FOR(i, 0, pacientes)
        fila.PB(i+1);
    }
    
    FOR(i, 0, querys){
      cin >> aux;
      
      if(aux == "N"){
        cout << fila.F() << "\n";
        fila.PB(fila.F());
        fila.P_F();
      }
      else{
        cin >> datum;
        forit(x, fila)
          if(*x == datum){
            fila.erase(x);
            break;
          }
        fila.PF(datum);
      }
    }
    
    fila.clear();
    cases++;
  }
  
  return 0;
}