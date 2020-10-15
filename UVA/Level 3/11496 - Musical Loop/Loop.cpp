#include <iostream>
using namespace std;

int main()
{
  int samples, picos;
  int centro[10020], izquierda[10020];
  int crece, decrece;
  while(cin >> samples, samples)
  {
    picos = 0;
    crece = 0;
    decrece = 0;
    for(int i = 0; i < samples; i++)
    {
      cin >> centro[i];
      izquierda[i+1] = centro[i];
    }
    izquierda[0] = centro[samples-1];
    
    if(centro[0] > izquierda[0])
      {
        crece = 1;
      }
    else
      {
        decrece = 1;
      }
    
    for(int i = 1; i < samples; i++)
    {
      if(crece)
      {
        if(centro[i] < izquierda[i])
        {
          decrece = 1;
          crece = 0;
          picos++;
        }
      }
      else if(decrece)
      {
        if(centro[i] > izquierda[i])
        {
          crece = 1;
          decrece = 0;
          picos++;
        }
      }
    }
    if(crece)
      {
        if(centro[0] < izquierda[0])
        {
          picos++;
        }
      }
    else
      {
        if(centro[0] > izquierda[0])
        {
          picos++;
        }
      }
    cout << picos << endl;
  }
  
  return 0;
}