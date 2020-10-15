#include <iostream>
using namespace std;

int main()
{
  int cases, trademark, query, nAutos;
  int precioMinimo[10020], precioMaximo[10020];
  string marcas[10020], laMarca;
  
  cin >> cases;
  
  for(int a = 0; a < cases; a++)
  {
    nAutos = 0;
    cin >> trademark;
    for(int i = 0; i < trademark; i++)
    {
      cin >> marcas[i];
      cin >> precioMinimo[i];
      cin >> precioMaximo[i];
    }
    
    cin >> query;
    for(int i =0; i<query; i++)
    {
      int contador;
      cin >> contador;
      for(int j=0; j<trademark; j++)
      {
        if(contador<=precioMaximo[j] and contador>=precioMinimo[j])
        {
          laMarca = marcas[j];
          nAutos++;
        }
        if(nAutos > 1)
        {
          break;
        }
      }
      
      if(nAutos == 0)
      {
        cout << "UNDETERMINED" << endl;
      }
      else 
      if(nAutos == 1)
      {
        cout << laMarca << endl;
        nAutos = 0;
      }
      else
      {
        cout << "UNDETERMINED" << endl;
        nAutos = 0;
      }
    }
    
    if(a != cases-1)
      cout << endl;
    
  }
  
	return 0;
}
