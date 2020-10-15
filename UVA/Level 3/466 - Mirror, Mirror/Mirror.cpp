#include <iostream>
using namespace std;


void rotar270(string original[], string arr2[], string nueva[], int *estado, int tamano)
{
  int datoInterno;
  *estado = 0;
  for(int i=0; i<tamano; i++)
  {
    for(int j=tamano-1; j>=0; j--)
    {
      datoInterno = original[j][i];
      arr2[i] += datoInterno;
    }
    if(arr2[i] != nueva[i])
      *estado = 1;
  }
}

void reflexion(string nueva[], string arr[],int *estado, int tamano)
{
  *estado = 0;
  for(int i=0; i<tamano; i++)
  {
    if(nueva[i] != arr[tamano-1-i])
    {
      *estado = 1;
      break;
    }
  }
}

int main()
{
  int tamano, contador=0, copiaTamano;
  string original[10], nueva[10];
  string g90[10], g180[10], g270[10];
  int estado, datoInterno;
  while(cin >> tamano)
  {
    for(int i=0; i<10; i++)
    {
      original[i] = "";
      nueva[i] = "";
      g90[i] = "";
      g180[i] = "";
      g270[i] = "";
    }
    
    copiaTamano = tamano;
    contador++;
    estado=0;
    
    for(int i=0; i<tamano; i++)
    {
        cin >> original[i];
        cin >> nueva[i];
        if(original[i] != nueva[i])
        {
          estado = 1;
        }
    }
    
    if(estado)
    {
      rotar270(original, g270, nueva, &estado, tamano);
      
      if(estado)
      {
        rotar270(g270, g180, nueva, &estado, tamano);
        
        if(estado)
        {
          rotar270(g180, g90, nueva, &estado, tamano);
          if(estado)
          {
            reflexion(nueva, g90, &estado, tamano);
            
            if(estado)
            {
              reflexion(nueva, g180, &estado, tamano);
              
              if(estado)
              {
                reflexion(nueva, g270, &estado, tamano);
                
                if(estado)
                {
                  reflexion(nueva, original, &estado, tamano);
                  if(estado)
                  {
                    cout << "Pattern " << contador << " was improperly transformed." << endl;
                  }
                  else
                  {
                    cout << "Pattern " << contador << " was reflected vertically." << endl;
                  }
                }
                else
                {
                  cout << "Pattern " << contador << " was reflected vertically and rotated 270 degrees." << endl; //C
                }
              }
              else
              {
                cout << "Pattern " << contador << " was reflected vertically and rotated 180 degrees." << endl;
              }
            }
            else
            {
              cout << "Pattern " << contador << " was reflected vertically and rotated 90 degrees." << endl; //C
            }
          }
          else
          {
             cout << "Pattern " << contador << " was rotated 270 degrees." << endl; //CAMBIADO
          }
        }
        else
        {
           cout << "Pattern " << contador << " was rotated 180 degrees." << endl;
        }
      }
      else
      {
        cout << "Pattern " << contador << " was rotated 90 degrees." << endl; //CAMBIADO
      }
    }
    else
    {
      cout << "Pattern " << contador << " was preserved." << endl;
    }
  }
  
  return 0;
}