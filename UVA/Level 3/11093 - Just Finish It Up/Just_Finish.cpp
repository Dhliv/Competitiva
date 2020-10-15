#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream archivo;
  int test, stations, gasolinaTotal, gasolinaNecesaria, posicion;
  int estacionGasolina[100020];
  int gasolinaGastada[100020];
  int gasolinaEnTanque, gasolinaRecorrida;
  archivo.open("archivo.txt");
  
  
  archivo >> test;
  
  for(int i = 0; i < test; i++)
  {
    archivo >> stations;
    gasolinaTotal = 0;
    gasolinaNecesaria = 0;
    gasolinaEnTanque = 0;
    gasolinaRecorrida = 0;
    posicion = 0;
    
    for(int j = 0; j < stations; j++)
    {
      archivo >> estacionGasolina[j];
      gasolinaTotal += estacionGasolina[j];
    }
    
    for(int j = 0; j < stations; j++)
    {
      archivo >> gasolinaGastada[j];
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
  
  archivo.close("archivo.txt");
  return 0;
}