#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned int n, maxUI, last, cases;
  for(int i=0; i<32; i++) maxUI|=(1<<i);
  cin >> cases;
  for(int j=0; j<cases; j++){
    cin >> n;
    unsigned int r=0;

      for(int i=0; i<32; i++){
        r|= 1<<(n&31);
        last = n&1;
        n>>=1;
        n|= (last<<31);
      }

      if(maxUI == r) cout << "yes" << endl;
      else cout << "no" << endl;
  }

  return 0;
}