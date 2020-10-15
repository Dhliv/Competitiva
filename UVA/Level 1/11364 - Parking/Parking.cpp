#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int cases, calles, answer, inicial;
  int numeros[105];
  
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    answer = 0;
    cin >> calles;
    
    for(int j = 0; j < calles; j++)
      cin >> numeros[j];
    
    sort(numeros, numeros + calles);
    
    for(int j = 1; j < calles; j++)
      answer += (numeros[j] - numeros[j-1]);
    
    answer += abs(numeros[0] - numeros[calles-1]);
    
    cout << answer << endl;
  }
    
	return 0;
}