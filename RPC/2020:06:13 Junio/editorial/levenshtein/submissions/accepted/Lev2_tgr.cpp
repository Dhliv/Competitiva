#include <iostream>
#include <string>
#include <set>
using namespace std ;
string alpha, s, m ;
set<string> r ;
void lev(int at, int need) {
   if (at >= (int)s.size() && !need) {
      r.insert(m) ;
      return ;
   }
   if (at < (int)s.size() && need) // delete current char
      lev(at+1, 0) ;
   for (char c : alpha) {
      m.push_back(c) ;
      if (need) // insert this character
         lev(at, 0) ;
      if (at < (int)s.size() && (need || c == s[at]))
                // change a character, or no change
         lev(at+1, need && c == s[at]) ;
      m.pop_back() ;
   }
}
int main() {
   cin >> alpha >> s ;
   lev(0, 1) ;
   for (auto s : r)
      cout << s << endl ;
}
