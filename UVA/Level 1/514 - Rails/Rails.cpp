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
  int vagones, fE, cont;
  DQ pila, copiaP, station;
  bool poss;

  while(cin >> vagones, vagones){
    int orden[vagones];
    for(int i = vagones; i > 0; i--)
      pila.PF(i);

    while(cin >> fE, fE){
      poss = false;
      cont = 0;
      copiaP = pila;
      orden[0] = fE;
      FOR(i, 1, vagones)
        cin >> orden[i];
      
      while(true){
        if(copiaP.size() + station.size()){
          if(station.empty()){
            if(copiaP.F() == orden[cont]){
              cont++;
              copiaP.P_F();
            }else{
              station.PF(copiaP.F());
              copiaP.P_F();
            }
          }else{
            if(copiaP.empty()){ //CASO IMPOSIBLE
              if(station.F() == orden[cont]){
                cont++;
                station.P_F();
              }else
                break;
            }else{
              if(copiaP.F() == orden[cont]){
                cont++;
                copiaP.P_F();
              }else if(station.F() == orden[cont]){
                cont++;
                station.P_F();
              }else{
                station.PF(copiaP.F());
                copiaP.P_F();
              }
            }
          }
        }else{
          poss = true;
          break;
        }
      }
      
      station.clear();
      
      if(poss)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
    pila.clear();
    cout << "\n";
  }

  
  return 0;
}