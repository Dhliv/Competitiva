#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  ifstream archivo;
  archivo.open("archivo.txt");
  ofstream archivoSalida("test.txt");
  int cabezas, guerreros, cabezasRestantes, pagar;
  int cabeza[20020], guerrero[20020], inicio;
  
  while(archivo >> cabezas, archivo >> guerreros, guerreros+cabezas)
  {
    pagar = 0;
    inicio =0;
    cabezasRestantes = cabezas;
    
      for(int i=0; i<cabezas; i++)
      {
          archivo >> cabeza[i];
      }
      
    for(int i = 0; i < guerreros; i++)
    {
      archivo >> guerrero[i];
    }
    
    
    if(cabezas<=guerreros)
    {
      sort(cabeza,cabeza + cabezas);
      sort(guerrero,guerrero + guerreros);
      for(int i=0; i<cabezas; i++)
      {
        for(int j=inicio; j<guerreros; j++)
        {
          if(guerrero[j] >= cabeza[i])
          {
            pagar+= guerrero[j];
            guerrero[j] = -1;
            cabezasRestantes--;
            inicio = j;
            break;
          }
        }
      }
    
      if(cabezasRestantes>0)
      {
        archivoSalida << "Loowater is doomed!" << endl;
      }
      else
      {
        archivoSalida << pagar << endl;    
      }
    }
    else
    {
        archivoSalida << "Loowater is doomed!" << endl;
    }
  }
  return 0;
}