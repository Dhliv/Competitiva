#include <iostream>
using namespace std;

int main()
{
	int sets, contador, altura, pasos, aux;
	int stacks[55], estadoBricks[55];
	contador = 1;
	
	while(cin >> sets, sets)
	{
	  pasos = 0;
	  altura = 0;
	  
	  for(int i = 0; i < 55; i++)
	    estadoBricks[i] = 0;
	  
	  for(int i = 0; i < sets; i++)
	  {
	    cin >> stacks[i];
	    altura += stacks[i];
	  }
	  altura /= sets; 
	  
	  for(int i = 0; i < sets; i++)
	    estadoBricks[i] = stacks[i] - altura;
	  
	  for(int i = 0; i < sets; i++)
	  {
	    for(int j = 0; j < sets; j++)
	    {
	      if(estadoBricks[i] > 0 and estadoBricks[j] < 0)
	      {
	      	aux = estadoBricks[i] + estadoBricks[j];
	      	if(aux > 0)
	      	{
	      		pasos += estadoBricks[i] - aux;
	      		estadoBricks[i] = aux;
	      		estadoBricks[j] = 0;
	      	}
	      	else
	      	{
	      		pasos += estadoBricks[i];
	      		estadoBricks[j] += estadoBricks[i];
	      		estadoBricks[i] = 0;
	      	}
	      }
	    }
	  }
	  
	  cout << "Set #" << contador << endl;
	  cout << "The minimum number of moves is " << pasos << "." << endl << endl;
	  contador++;
	}
	
	return 0;
}