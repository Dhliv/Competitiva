#include <iostream>
using namespace std;

int main()
{
  int cases, students, max, min;
  
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    cin >> students;
    cin >> max;
    
    for(int j = 0; j < students-1; j++)
    {
      cin >> min;
      if(min > max)
        max = min;
    }
    
    cout << "Case " << i+1 << ": " << max << endl;
    max = 0;
  }
  
  return 0;
}