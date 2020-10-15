#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  int mas = 0, menos = 0, unk = 0, faltantes;
  char MAS = '+', MENUS = '-';
  double p = 1.0;
  string s;
  cin >> s;

for(int i = 0; i < s.length(); i++){
  if(s[i] == MAS)
    mas++;
  else
    menos++;
}

cin >> s;

for(int i = 0; i < s.length(); i++){
  if(s[i] == MAS)
    mas--;
  else if(s[i] == MENUS)
    menos--;
  else
    unk++;
}
if(mas < 0 or menos < 0){
  cout << 0 << endl;
  return 0;
}

double aux1=1, aux2=1;
for(int i=1; i<menos+1; i++)
{
  aux1 *= i; 
}
for(int i=1; i<mas+1; i++)
{
  aux2 *= i; 
}
aux1 *= aux2;
aux2 = 1;
for(int i=1; i<unk+1; i++)
  aux2 *= i;

aux1= aux2/aux1;

aux1 = aux1/pow(2, unk);



cout.precision(20);
cout << aux1 << endl;
  
  //map<long long int, long long int> leMape;
  //leMape.insert(pair <long long int, long long int>(op, i));
  return 0;
}
