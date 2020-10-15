#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
  map<string, int> leMape;
  string arr[26];
  string dato = "", word;
  int pos1, pos2, pos3, pos4, pos5;
  
  for(int i=97; i<123; i++)
  {
    dato += char(i);
    arr[i-97] = dato;
    leMape.insert(pair<string, int>(dato, i-96));
    dato = "";
  }
  
  pos1 = 0;
  pos2 = 1;
  pos3 = 1;
  pos4 = 1;
  pos5 = 1;
  int numero = 26;
  
  for(int i = pos1; i < 26; i++)
  {
    for(int j = pos2+i; j < 26; j++)
    {
      string cadena = arr[i] + arr[j];
      numero++;
      leMape.insert(pair<string, int>(cadena, numero));
    }
  }
  
  for(int i = pos1; i < 26; i++)
  {
    for(int j = pos2+i; j < 26; j++)
    {
      for(int k = pos3+j; k < 26; k++)
      {
        string cadena = arr[i] + arr[j] + arr[k];
        numero++;
        leMape.insert(pair<string, int>(cadena, numero));
      }
    }
  }
  
  for(int i = pos1; i < 26; i++)
  {
    for(int j = pos2+i; j < 26; j++)
    {
      for(int k = pos3+j; k < 26; k++)
      {
        for(int l = pos4+k; l < 26; l++)
        {
          string cadena = arr[i] + arr[j] + arr[k] + arr[l];
          numero++;
          leMape.insert(pair<string, int>(cadena, numero));
        }
      }
    }
  }
  
  for(int i = pos1; i < 26; i++)
  {
    for(int j = pos2+i; j < 26; j++)
    {
      for(int k = pos3+j; k < 26; k++)
      {
        for(int l = pos4+k; l < 26; l++)
        {
          for(int m = pos5+l; m < 26; m++)
          {
            string cadena = arr[i] + arr[j] + arr[k] + arr[l] + arr[m];
            numero++;
            leMape.insert(pair<string, int>(cadena, numero));
          }
        }
      }
    }
  }
  
  while(cin >> word)
  {
    if(leMape.find(word) != leMape.end())
    {
      cout << leMape.find(word)->second << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }
  
  return 0;
}