#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c, cont;
  cin >> a >> b >> c;
  cont =0;
  for(int i=1; i<a; i++){
    if( (i%b == i%c) && (i%b == 0) || (i%c == 0)) cont++;
    else{
      if(i%b == 0) cont++;
      if(i%c == 0) cont++;
    }
  }
  cout << cont << endl;


  return 0;
}