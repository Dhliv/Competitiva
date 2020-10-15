#include <iostream>
using namespace std;

int main()
{
  int grupos, longGrupo;
  string cadena, subcadena;
  
  while(cin >> grupos, grupos)
  {
    cin >> cadena;
    subcadena = cadena;
    longGrupo = (cadena.length())/grupos;
    int contador = longGrupo;
      
    for(int i=0; i<grupos; i++)
    {
      for(int j=0; j<longGrupo; j++)
      {
        subcadena[i*longGrupo+j] = cadena[i*longGrupo+longGrupo-1-j];
      }
    }
    cout << subcadena << endl;

  }
  return 0;
}