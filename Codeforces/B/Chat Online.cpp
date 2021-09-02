
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  int amA, amB, limIzq, limDer, tiempos = 0;
  bool salir;

  cin >> amA >> amB >> limIzq >> limDer;

  int diasA[amA][2], diasB[amB][2];

  for(int i = 0; i < amA; i++)
    cin >> diasA[i][0] >> diasA[i][1];

  for(int i = 0; i < amB; i++)
    cin >> diasB[i][0] >> diasB[i][1];


  for(int rep = limIzq; rep <= limDer; rep++){

    salir = false;

    for(int i = 0; i < amA; i++){

      for(int j = 0; j < amB; j++){

        if(((diasB[j][0]+rep) >= diasA[i][0]) && ((diasB[j][0]+rep) <= diasA[i][1])){
          tiempos++;
          salir = true;
          break;
        }

        else if(((diasB[j][1]+rep) >= diasA[i][0]) && ((diasB[j][1]+rep) <= diasA[i][1])){
          tiempos++;
          salir = true;
          break;
        }
        //else if()
        
        else if(diasB[j][0]+rep <= diasA[i][0] && diasB[j][1]+rep >= diasA[i][1]){
            tiempos++;
          salir = true;
          break;
        }
      }
      if(salir)
        break;
    }
  }


  cout << tiempos;


  //map<long long int, long long int> leMape;
  //leMape.insert(pair <long long int, long long int>(op, i));
  return 0;
}
