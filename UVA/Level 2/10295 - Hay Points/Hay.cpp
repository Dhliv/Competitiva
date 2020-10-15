#include <iostream>
#include <map>
using namespace std;

int main()
{
  map <string, int> leMape;
  long long dinero;
  int palabras, textos;
  string cadena;
  
  cin >> palabras;
  cin >> textos;
  
  for(int i = 0; i < palabras; i++)
  {
    cin >> cadena;
    cin >> dinero;
    leMape.insert(pair<string, int>(cadena, dinero));
  }
  
  for(int i = 0; i < textos; i++)
  {
    dinero = 0;
    while(cin >> cadena, cadena != ".")
    {
      if(leMape.find(cadena) != leMape.end())
      {
        dinero += leMape.find(cadena)->second;
      }
    }
    cout << dinero << endl;
  }
  return 0;
}