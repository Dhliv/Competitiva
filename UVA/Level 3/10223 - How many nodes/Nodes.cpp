#include <iostream>
using namespace std;

int main()
{
  long long int catalan[21] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796,
                                58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790,
                                477638700 ,1767263190 ,6564120420};
  long long int number;
  
  while(cin >> number)
  {
    if(number == 1)
    {
      cout << 1 << endl;
    }
    else
    {
      for(int i=0; i<22; i++)
      {
        if(catalan[i] >= number)
        {
          cout << i << endl;
          break;
        }
      }
    }
  }

  return 0;
}