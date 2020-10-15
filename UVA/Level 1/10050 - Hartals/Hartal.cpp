#include <iostream>
using namespace std;

int main()
{
  int cases, dias, partys, aux, hartal;
  int hash[3700];
  
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    for(int j = 0; j < 3700; j++)
    {
      hash[j] = 0;
    }
    
    hartal = 0;
    cin >> dias;
    cin >> partys;
    
    for(int j = 0; j < partys; j++)
    {
      int veces = 0;
      cin >> aux;
      veces = dias / aux;
      
      for(int k = 1; k <= veces; k++)
      {
        int posicion = aux * k;
        if((posicion % 7) == 6 or (posicion % 7) == 0)
        {
          hash[posicion] = 0;
        }
        else
        {
          hash[posicion] = 1;
        }
      }
    }
    
    for(int j = 0; j < 3700; j++)
    {
      if(hash[j] == 1)
      {
        hartal++;
      }
    }
    
    cout << hartal << endl;
  }
  
  return 0;
}