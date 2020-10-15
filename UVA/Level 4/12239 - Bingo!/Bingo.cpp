#include <iostream>
using namespace std;

int main()
{
  int fichas, canicas, b, maximoDeNumeros;
  int hash, estado;
  int loQueTengo[100], sumas[200];
  
  while(cin >> fichas, cin >> canicas, canicas+fichas)
  {
    maximoDeNumeros = canicas*(canicas-1)/2 + canicas;
    estado = 1;
    for(int i = 0; i <= fichas; i++)
    {
      loQueTengo[i] = 0;
      sumas[i] = 0;
    }
    loQueTengo[fichas+1] = 0;
      
    for(int i = 0; i < canicas; i++)
    {
      cin >> b;
      loQueTengo[b] = b;
      sumas[b] = 1;
    }
    
    if(sumas[fichas] != 1)
      cout << "N" << endl;
    else if(maximoDeNumeros < fichas+1)
      cout << "N" << endl;
    else if(!sumas[0])
      cout << "N" << endl;
    else
    {
      for(int i = 0; i <= fichas; i++)
      {
        for(int j = i; j <= fichas; j++)
        {
          hash = abs(loQueTengo[i] - loQueTengo[j+1]);
          sumas[hash] = 1;
        }
      }
        
      for(int i=0; i <= fichas; i++)
      {
        if(sumas[i] != 1)
        {
          cout << "N" << endl; 
          estado = 0;
          break;
        }
      }
      if(estado)
        cout << "Y" << endl;
    }
  }
  
  return 0;
}