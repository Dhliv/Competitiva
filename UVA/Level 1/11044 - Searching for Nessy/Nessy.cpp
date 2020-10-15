#include <iostream>
using namespace std;

int main()
{
  int cases, fila, columna, total;
  
  cin >> cases;
  
  for(int a = 0; a < cases; a++)
  {
    total = 0;
    cin >> fila;
    cin >> columna;
    total = (fila/3) * (columna/3);
    cout << total << endl;
  }
  
  return 0;
}