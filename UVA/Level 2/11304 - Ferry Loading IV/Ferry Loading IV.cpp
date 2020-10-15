#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <math.h>
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
typedef map<int,int> mapa;

int main()
{
  ll cases, len, comms, aux, cruzar, carga;
  DQ left, right;
  bool izq;
  string dir;
  cin >> cases;
  
  FOR(num, 0, cases){
    cin >> len >> comms;
    len *= 100;
    izq = true;
    cruzar = 0;
    carga = 0;
    
    FOR(i, 0, comms){
      cin >> aux >> dir;
      if(dir == "left")
        left.PB(aux);
      else
        right.PB(aux);
    }
    
    while(!left.empty() || !right.empty()){
      if(izq){
        aux = left.size();
        FOR(i, 0, aux){
          if(carga <= len){
            if(left.F() > len)
              left.P_F();
            else if(carga + left.F() <= len){
              carga += left.F();
              left.P_F();
            }else
              break;
          }else{
            if(left.F() > len)
              left.P_F();
            else
              break;
          }
        }
        cruzar++;
        carga = 0;
        izq = false;
        
      }else{
        aux = right.size();
        FOR(i, 0, aux){
          if(carga <= len){
            if(right.F() > len)
              right.P_F();
            else if(carga + right.F() <= len){
              carga += right.F();
              right.P_F();
            }else
              break;
          }else{
            if(right.F() > len)
              right.P_F();
            else
              break;
          }
        }
        cruzar++;
        carga = 0;
        izq = true;
      }
    }
    
    cout << cruzar << "\n";
  }
  
  return 0;
}