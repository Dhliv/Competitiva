#include <iostream>
using namespace std;

int main()
{
  int seq, sumaViable, sumaEtapa;
  int bets[10020];
  
  while(cin >> seq, seq)
  {
    for(int i = 0; i < seq; i++)
      cin >> bets[i];
      
    sumaViable = 0;
    sumaEtapa = 0;
    for(int i=0; i < seq; i++)
    {
      sumaEtapa += bets[i];
      if(sumaEtapa < 0)
      {
        sumaEtapa = 0;
      }
      else
      {
        if(sumaEtapa>sumaViable)
        {
          sumaViable = sumaEtapa;
        }
      }
    }
    
    if(sumaViable>0)
    {
      cout << "The maximum winning streak is " << sumaViable << "." << endl;
    }
    else
    {
      cout << "Losing streak." << endl;
    }
  }
  
  return 0;
}