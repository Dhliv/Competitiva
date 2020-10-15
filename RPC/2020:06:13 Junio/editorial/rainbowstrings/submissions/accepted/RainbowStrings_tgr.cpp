#include <iostream>
#include <vector>
#include <string>
using namespace std ;
typedef long long ll ;
ll MOD = 11092019 ;
int main() {
   string s ;
   cin >> s ;
   vector<int> cnt(256) ;
   for (auto c : s)
      cnt[(int)c]++ ;
   ll r = 1 ;
   for (auto v : cnt)
      r = (r * (v + 1)) % MOD ;
   cout << r << endl ;
}
