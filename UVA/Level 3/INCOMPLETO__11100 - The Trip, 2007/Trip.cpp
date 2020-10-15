#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int mochilas, numeroMaximo, excedente, datosCG, contador;
  int dimensiones[10020], numeros[10020][2];
  bool huboExcedente;
  
  while(cin >> mochilas, mochilas)
  {
    huboExcedente = false;
    contador =0;
    numeroMaximo = 0;
    int aux = 1;
    
    for(int i = 0; i < mochilas; i++)
    {
      cin >> dimensiones[i];
    }
    
    sort(dimensiones,dimensiones + mochilas);
    
    for(int i = 1; i < mochilas; i++)
    {
      numeros[contador][1] = aux;
      numeros[contador][0] = dimensiones[i-1];
      if(dimensiones[i] == dimensiones[i-1])
      {
        aux++;
        if(numeroMaximo < aux)
        {
          numeroMaximo = aux;
        }
      }
      else
      {
        aux = 1;
        contador++;
      }
    }
    
    numeros[contador][1] = aux;
    numeros[contador][0] = dimensiones[mochilas-1];
    cout << numeroMaximo << endl;
    datosCG = mochilas/numeroMaximo;
    excedente = mochilas % numeroMaximo;
    
    for(int i=0; i<numeroMaximo; i++)
    {
      aux = 0;
      if(excedente)
      {
        huboExcedente = true;
        for(int j=0; j<contador+1; j++)
        {
          if(aux < datosCG+1)
          {
            if(numeros[j][1])
            {
              if(aux<datosCG)
              {
                cout << numeros[j][0] << " ";
                numeros[j][1]--;
                aux++;
              }
              else
              {
                cout << numeros[j][0];
                numeros[j][1]--;
                aux++;
              }
            }
          }
        }
        cout << endl;
        excedente--;
      }
      else
      {
        if(huboExcedente)
        {
          
        }
        else
        {
          for(int j=0; j<contador+1; j++)
          {
            if(aux < datosCG)
            {
              if(numeros[j][1])
              {
                if(aux< datosCG-1)
                {
                  cout << numeros[j][0] << " ";
                  numeros[j][1]--;
                  aux++;
                }
                else
                {
                  cout << numeros[j][0] << endl;
                  numeros[j][1]--;
                  aux++;
                }
              }
            }
          }
        }
      }
    }
  }
  
  
  return 0;
}