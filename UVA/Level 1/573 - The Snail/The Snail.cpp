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
  int h, u, d, f, dias;
  double escalado, escalar, deslizamiento, altura, fatiga, factor, umbral;
  bool fondo, arriba;
  
  while(cin >> h >> u >> d >> f, h){
    escalado = 0.0, escalar = u*1.0, deslizamiento = d*1.0, dias = 1, altura = h*1.0;
    factor = f*1.0, fatiga = escalar*(factor/100), umbral = 100/factor;
    fondo = arriba = false;
    
    while(true){
      escalado += escalar;
      
      if(escalado < 0.0 or escalado - deslizamiento < 0.0){
        fondo = true;
        break;
      }
      else if(escalado > altura){
        arriba = true;
        break;
      }
      else{
        escalado -= deslizamiento;
        if(dias <= umbral)
          escalar -= fatiga;
        dias++;
      }
    }
    
    if(fondo)
      cout << "failure on day " << dias << "\n";
    else
      cout << "success on day " << dias << "\n";
  }
  
  return 0;
}