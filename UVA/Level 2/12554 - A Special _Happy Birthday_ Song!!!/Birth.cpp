#include <iostream>
using namespace std;

int main()
{
  string cadenas[5] = {"Happy", "birthday", "to", "you", "Rujia"};
  int activos[5] = {1, 0, 0, 0, 0};
  string nombres[110];
  int total;
  int limite = 16, contador = 1;
  
  cin >> total;
  
  if(total > limite)
    limite = 32;
  if(total > limite)
    limite = 48;
  if(total > limite)
    limite = 64;
  if(total > limite)
    limite = 80;
  if(total > limite)
    limite = 96;
  if(total > limite)
    limite = 112;
  
  for(int i = 0; i < limite; i++)
    nombres[i] = "";
  
  for(int i = 0; i < total; i++)
    cin >> nombres[i];
  
  for(int i = 0; i < limite; i++)
  {
    if(nombres[i] == "")
    {
      limite = limite - i;
      i = 0;
    }
    
    if(contador == 12 or contador == 28)
    {
      cout << nombres[i] << ": " << cadenas[4] << endl;
      activos[1] = 0;
      activos[2] = 0;
      activos[3] = 0;
      activos[0] = 1;
      contador = 12;
    }
    else if(activos[0] == 1)
    {
      cout << nombres[i] << ": " << cadenas[0] << endl;
      activos[0] = 0;
      activos[1] = 1;
    }
      
    else if(activos[1] == 1)
    {
      cout << nombres[i] << ": " << cadenas[1] << endl;
      activos[1] = 0;
      activos[2] = 1;
    }
      
    else if(activos[2] == 1)
    {
      cout << nombres[i] << ": " << cadenas[2] << endl;
      activos[2] = 0;
      activos[3] = 1;
    }
      
    else if(activos[3] == 1)
    {
      cout << nombres[i] << ": " << cadenas[3] << endl;
      activos[3] = 0;
      activos[0] = 1;
    }
    contador++;
  }
  
  return 0;
}