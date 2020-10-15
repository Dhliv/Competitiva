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
  int devices, ops, ampers, actual, best, aux, contador = 1;
  bool blown;
  
  while(cin >> devices >> ops >> ampers, devices+ampers+ops){
    cout << "Sequence " << contador++ << "\n";
    
    vector<int> amperaje(devices);
    vector<bool> isOn(devices);
    best = actual = 0;
    blown = false;
    
    FOR(i, 0, devices)
      cin >> amperaje[i];
    
    FOR(i, 0, ops){
      cin >> aux;
      if(!isOn[aux-1]){
        actual += amperaje[aux-1];
        if(actual > best)
          best = actual;
          
        if(actual > ampers)
          blown = true;
          
        isOn[aux-1] = !isOn[aux-1];
      }
      else{
        actual -= amperaje[aux-1];
        isOn[aux-1] = !isOn[aux-1];
      }
    }
    
    if(blown)
      cout << "Fuse was blown.\n\n";
    else
      cout << "Fuse was not blown.\nMaximal power consumption was " << best << " amperes.\n\n";
  }
  
  return 0;
}