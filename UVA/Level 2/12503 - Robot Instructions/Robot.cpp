#include <iostream>
using namespace std;

int main()
{
  int cases, posFinal, aux, numeroDatos;
  int instructions[110];
  string cadena;
  
  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    posFinal = 0;
    cin >> numeroDatos;
    
    for(int j = 1; j <= numeroDatos; j ++)
    {
      cin >> cadena;
      
      if(cadena == "LEFT")
      {
        posFinal--;
        instructions[j] = -1;
      }
      if(cadena == "RIGHT")
      {
        posFinal++;
        instructions[j] = 1;
      }
      if(cadena == "SAME")
      {
        cin >> cadena;
        cin >> aux;
        posFinal += instructions[aux];
        instructions[j] = instructions[aux];
      }
    }
    
    cout << posFinal << endl;
  }
  
  return 0;
}