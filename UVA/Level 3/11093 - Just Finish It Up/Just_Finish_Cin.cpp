#include <iostream>
using namespace std;

int main()
{
  int test, stations, gasolinaTotal, gasolinaNecesaria, posicion;
  int estacionGasolina[100020];
  int gasolinaGastada[100020];
  int gasolinaEnTanque, gasolinaRecorrida;
  
  cin >> test;
  
  for(int i = 0; i < test; i++)
  {
    cin >> stations;
    gasolinaTotal = 0;
    gasolinaNecesaria = 0;
    gasolinaEnTanque = 0;
    gasolinaRecorrida = 0;
    posicion = 0;
    
    for(int j = 0; j < stations; j++)
    {
      cin >> estacionGasolina[j];
      gasolinaTotal += estacionGasolina[j];
    }
    
    for(int j = 0; j < stations; j++)
    {
      cin >> gasolinaGastada[j];
      gasolinaNecesaria += gasolinaGastada[j];
    }
    
    if(gasolinaTotal < gasolinaNecesaria)
    {
      cout << "Case " << i+1 << ": Not possible" << endl;
    }
    else
    {
      for(int j=0; j<stations; j++)
      {
        gasolinaEnTanque += estacionGasolina[j];
        gasolinaRecorrida += gasolinaGastada[j];
        if(gasolinaEnTanque < gasolinaRecorrida)
        {
          //Proceso para saber si se puede completar la vuelta.
          gasolinaEnTanque = 0;
          gasolinaRecorrida = 0;
          posicion = j+1;
        }
      }
      cout << "Case " << i+1 << ": Possible from station " << posicion+1 << endl;
    }
    
  }
  
  return 0;
}