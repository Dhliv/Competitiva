#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
  string cadena;
  double cases, arboles;
  cin >> cases;
  cout.precision(4);
  getline(cin, cadena);
  getline(cin, cadena);
  
  for(int i = 0; i < cases; i++)
  {
    
    arboles=0;
    map<string, int> leMape;

    if(i == cases-1)
    {
      while(getline(cin, cadena))
      {
        arboles++;
        if(leMape.find(cadena) != leMape.end())
        {
          leMape.find(cadena)->second++;
        }
        else
        {
          leMape.insert(pair<string,double>(cadena, 1));
        }
      }
    }
    else
    {
      while(getline(cin, cadena), cadena != "")
      {
        arboles++;
        if(leMape.find(cadena) != leMape.end())
        {
          leMape.find(cadena)->second++;
        }
        else
        {
          leMape.insert(pair<string,double>(cadena, 1));
        }
      }
    }
    /*
    while (!leMape.empty())   caso de borrado.
    {
      double aprox = leMape.begin()->second/arboles*100;
      cout << leMape.begin()->first << " " << fixed <<  aprox << endl;
      leMape.erase(leMape.begin());
    }
    */
    
    map<string, int>::iterator itr;
    for (itr = leMape.begin(); itr != leMape.end(); ++itr)    // Explorador de los elementos.
    { 
      double aprox = itr->second/arboles*100;
      cout << itr->first << " " << fixed <<  aprox << endl;
    }
    
    if(i != cases-1)
    {
      cout << endl;
    }
  }
  
  return 0;
}