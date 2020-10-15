#include <iostream>
using namespace std;

int main()
{
  int cases, espanta, longitud;
  string cadena;
  
  cin >> cases;
  for(int a = 1; a <= cases; a++)
  {
    espanta = 0;
    cin >> longitud;
    cin >> cadena;
    
    for(int i=0; i<longitud; i++)
    {
      if(cadena[i] == '.')
      {
        espanta+=1;
        i+=2;
      }
    }
    
    cout << "Case " << a << ": " << espanta << endl;
  }
  
  return 0;
}