#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  double n, r1, m, p1, k, p2, A, B, maxAux;
  long long minimo = 0;
  double r2;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> maxAux;
    if(maxAux > minimo)
      minimo = maxAux;
  }
  r1 = minimo;

  minimo = 0;  
  cin >> m;
  for(int i=0; i<m; i++)
  {
    cin >> maxAux;
    if(maxAux > minimo)
      minimo = maxAux;
  }
  p1 = minimo;

  minimo = 1000000000000000;
  cin >> k;
  for(int i=0; i<k; i++)
  {
    cin >> maxAux;
    if(maxAux < minimo)
      minimo = maxAux;
  }
  p2 = minimo;
  
  cin >> A >> B;

  r2 = r1/(sqrt(1 + (A * p2)/(B * p1)));

  cout.precision(20);
  cout << r2 << endl;


  //map<long long int, long long int> leMape;
  //leMape.insert(pair <long long int, long long int>(op, i));
  return 0;
}
