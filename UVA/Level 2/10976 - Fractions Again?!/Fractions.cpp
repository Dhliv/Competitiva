#include <iostream>
using namespace std;

int main()
{
  int denominador, x, y, contador, xy[10020][2];
  
  while(cin >> denominador)
  {
    contador=0;
    for(int i = denominador+1; i <= denominador*2; i++)
    {
      y = i;
      x = (denominador*y);
      if(x%(y - denominador) == 0)
      {
        xy[contador][0] = x/(y - denominador);
        xy[contador][1] = y;
        contador++;
      }
    }
    
    cout << contador << endl;
    
    for(int i = 0; i < contador; i++)
    {
      cout << "1/" << denominador <<  " = 1/" << xy[i][0] << " + 1/" << xy[i][1] << endl;
    }
  }
  
  return 0;
}