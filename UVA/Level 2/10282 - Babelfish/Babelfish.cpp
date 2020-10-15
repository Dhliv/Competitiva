#include <iostream>
#include <map>
using namespace std;

int main()
{
  string oracion, palabra, traduccion;
  int contador;
  map <string, string> leMape;
  while(getline(cin, oracion))
  {
    if(oracion != "")
    {
      palabra = "";
      traduccion = "";
      contador = 0;
      for(int i=0; i<oracion.length(); i++)
      {
        if(oracion[i] != ' ')
        {
          palabra+= oracion[i];
        }
        else
        {
          contador = i+1;
          break;
        }
      }
      
      for(int i=contador; i<oracion.length(); i++)
      {
          traduccion+= oracion[i];
      }
      
      leMape.insert(pair<string, string>(traduccion, palabra));
    }
    else
    {
      break;
    }
  }
  
  while(cin >> traduccion)
  {
    if(leMape.find(traduccion) != leMape.end())
    {
      cout << leMape.find(traduccion)->second << endl;
    }
    else
    {
      cout << "eh" << endl;
    }
  }
  return 0;
}