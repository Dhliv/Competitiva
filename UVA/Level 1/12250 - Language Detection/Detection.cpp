#include <iostream>
using namespace std;

int main()
{
  string cadena;
  int contador = 1;
  
  while(cin >> cadena, cadena != "#")
  {
    cout << "Case " << contador << ": ";
    if(cadena == "HELLO")
      cout << "ENGLISH" << endl;
    else if(cadena == "HOLA")
      cout << "SPANISH" << endl;
    else if(cadena == "HALLO")
      cout << "GERMAN" << endl;
    else if(cadena == "BONJOUR")
      cout << "FRENCH" << endl;
    else if(cadena == "CIAO")
      cout << "ITALIAN" << endl;
    else if(cadena == "ZDRAVSTVUJTE")
      cout << "RUSSIAN" << endl;
    else
      cout << "UNKNOWN" << endl;
    contador++;
  }
  
  return 0;
}