#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{
  int number, n;
  int arr[1000000];
  multimap<int, int> leMape;
  for(int i=0; i<1000000; i++)
  {
    arr[i] = 0;
  }
  
  n=1;
  
  while(cin >> number)
  {
    for(int i=0; i<n; i++)
    {
      if(arr[i] == number)
        {
          break;
        }
      if(arr[i] == 0)
      {
        arr[i] = number;
        n++;
        break;
      }
    }
    leMape.insert(make_pair(number, number));
  }
  for(int i=0; i<n-1; i++)
  {
    cout << arr[i] << " " << leMape.count(arr[i]) << endl;
  }
  return 0;
}