#include <iostream>
#include <string>
using namespace std;

int main()
{
  int cases;
  int hash[10];
  string elNumero;
  int elOtroNumero;
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    for(int j = 0; j < 10; j++)
      hash[j] = 0;
    
    cin >> elOtroNumero;
    for(int j = 1; j <= elOtroNumero; j++)
    {
      elNumero = to_string(j);
      for(int k=0; k<elNumero.length(); k++)
      {
        int c = elNumero[k] - '0';
        hash[c]++;
      }
    }
    
    for(int j = 0; j < 9; j++)
    {
      cout << hash[j] << " ";
    }
    cout << hash[9] << endl;
  }
  
  return 0;
}