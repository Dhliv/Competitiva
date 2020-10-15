#include <iostream>
using namespace std;

int main()
{
  int cases, numero, answer;
  cin >> cases;
  
  for(int i = 0; i < cases; i++)
  {
    cin >> numero;
    numero = ((((((numero*567)/9)+7492)*235)/47)-498);
    answer = abs((numero % 100)/10);
    
    cout << answer << endl;
  }
    
	return 0;
}