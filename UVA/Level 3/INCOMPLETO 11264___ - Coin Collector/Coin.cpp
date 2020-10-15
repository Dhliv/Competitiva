#include <iostream>
using namespace std;

int main()
{
  int cases, nMonedas, monedasFinales, monto;
  cin >> cases;
  for(int i=0; i<cases; i++)
  {
    monedasFinales = 1;
    cin >> nMonedas;
    cin >> monto;
    for(int j=0; j<nMonedas; j++)
    {
      int aux;
      cin >> aux;
      if(monto<aux)
      {
        monto+=aux;
        monedasFinales++;
      }
    }
    
    cout << monedasFinales << endl;
  }
	return 0;
}
