#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std ;
void calccodelengths(vector<int> &v, int togo, int sofar) {
   if (sofar)
      v.push_back(sofar-1) ;
   if (togo) {
      calccodelengths(v, togo-1, sofar+2) ;
      calccodelengths(v, togo-1, sofar+4) ;
   }
}
int main() {
   vector<int> v ;
   calccodelengths(v, 7, 0) ; // we'll only use a small subset of these.
   sort(v.begin(), v.end()) ; // shortest first
   string s ;
   while (getline(cin, s)) {
      vector<int> cnts(26) ;
      for (char c : s) {
         if ('a' <= c && c <= 'z')
            cnts[c-'a']++ ;
         else if ('A' <= c && c <= 'Z')
            cnts[c-'A']++ ;
      }
      sort(cnts.begin(), cnts.end()) ;
      int sum = -3 ;
      for (int i=0; i<26; i++)
         sum += 3 * cnts[25-i] + cnts[25-i] * v[i] ;
      cout << sum << endl ;
   }
}
