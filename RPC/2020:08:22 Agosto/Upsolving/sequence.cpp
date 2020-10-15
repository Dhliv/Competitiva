#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int cases;
  unsigned long long s;

  cin >> cases;
  for(int i=0; i<cases; i++){

    cin >> s;
    cout << ((s+1)*(s+1)-1) << endl;
  }

  return 0;
}