#include <iostream>
using namespace std;

int main()
{
  int cigarillos, colillas, cigarillosFumados;
  
  while(cin >> cigarillos, cin >> colillas)
  {
    cigarillosFumados = cigarillos;
    while(cigarillos >= colillas)
    {
      cigarillosFumados += cigarillos/colillas;
      cigarillos = (cigarillos/colillas) + (cigarillos%colillas);
    }
    cout << cigarillosFumados << endl;
  }
  
  return 0;
}