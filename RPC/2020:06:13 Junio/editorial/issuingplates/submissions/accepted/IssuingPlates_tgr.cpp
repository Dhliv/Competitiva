#include <iostream>
#include <string>
#include <vector>
using namespace std ;
typedef long long ll ;
char letmap[] = { 'O', 'L', 'Z', 'E', '4', 'S', 'B', 'T', 'B', '9' } ;
int main() {
   int wc, platecount ;
   cin >> wc >> platecount ;
   vector<string> w(wc) ;
   for (auto &v : w)
      cin >> v ;
   for (int k=0; k<platecount; k++) {
      string checkme ;
      cin >> checkme ;
      for (auto &c : checkme)
         if (c <= '9')
            c = letmap[c-'0'] ;
      int good = 1 ;
      for (auto wrd : w)
         if (checkme.find(wrd) != string::npos) {
            good = 0 ;
            break ;
         }
      cout << (good ? "VALID" : "INVALID") << endl ;
   }
}
