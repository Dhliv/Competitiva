#include <iostream>
using namespace std;

int main()
{
  
  int cases, pertiga, hormigas, menor, mayor, pertigaMitad, mitad;
  
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    cin >> pertiga;
    cin >> hormigas;
    
    menor = 10000000;
    mayor = 0;
    pertigaMitad = pertiga/2;
    mitad = 10000000;
    
    for(int j=0; j<hormigas; j++)
    {
      int ant, mitadAux;
      cin >> ant;
      if(menor > ant)
        menor = ant;
      if(mayor < ant)
        mayor = ant;
      mitadAux = pertigaMitad-ant;
      if(abs(mitad-pertigaMitad) > abs(mitadAux))
      {
        if(mitadAux >= 0)
        {
          mitad = ant;
        }
        else
        {
          mitad = pertiga - ant;
        }
      }
    }
    if(pertiga-menor > mayor)
    {
      cout << mitad << " " << pertiga-menor << endl;
    }
    else
    {
      cout << mitad << " " << mayor << endl;
    }
  }
  
  return 0;
}