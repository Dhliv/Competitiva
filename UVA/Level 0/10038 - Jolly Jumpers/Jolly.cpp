#include <iostream>
using namespace std;

int main()
{
	int numeros, a, b, estado;
	int hash[3050];
	
	while(cin >> numeros)
	{
	  cin >> a;
	  estado = 1;
	  if(numeros == 1)
	    cout << "Jolly" << endl;
	  else
	  {
	    for(int i = 1; i < numeros; i++)
	      hash[i] = 0;
	   
	    for(int i = 0; i < numeros-1; i++)
	    {
	      cin >> b;
	      hash[abs(a - b)] = 1;
	      a = b;
	    }
	    
	    for(int i = 1; i < numeros; i++)
	    {
	      if(hash[i] == 0)
	        estado = 0;
	    }
	    
	    if(estado)
	      cout << "Jolly" << endl;
	    else
	      cout << "Not jolly" << endl;
	  }
	}
	
	return 0;
}
