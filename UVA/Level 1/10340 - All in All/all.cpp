#include <iostream>
#include <string>
using namespace std;

int main()
{
  int pos;
  string cadena1, cadena2;
  char letraCompare;
  while (cin >> cadena1, cin >> cadena2)
  {
    pos = 0;
    int estado = 1;
    for(int i=0; i<cadena1.length(); i++)
    {
      letraCompare = cadena1[i];
      if(estado)
      {
        for(int j=pos; j<cadena2.length(); j++)
        {
          if(letraCompare == cadena2[j])
          {
            estado =1;
            pos = j+1;
            break;
          }
          else
          {
            estado = 0;
          }
        }
      }
    }
    if(estado)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}