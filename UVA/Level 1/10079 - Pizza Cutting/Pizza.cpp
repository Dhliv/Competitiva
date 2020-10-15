#include <iostream>
using namespace std;
int main()
{
  long long int cortes;
  long double n;
  while(cin >> n, n >= 0)
  {
    cortes = (n*n/2) + (n/2) + 1;
    cout << cortes << endl;
  }
  return 0;
}