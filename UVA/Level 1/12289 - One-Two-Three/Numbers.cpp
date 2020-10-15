#include <iostream>
#include <string>
using namespace std;

int main()
{
  int cases;
  string cadena;
  
  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    cin >> cadena;
    
    if(cadena.length() == 5)
      cout << 3 << endl;
    else
    {
      if((cadena[0] == 'o' and cadena[1] == 'n') or (cadena[0] == 'o' and cadena[2] == 'e') or (cadena[2] == 'e' and cadena[1] == 'n'))
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
    
	return 0;
}
