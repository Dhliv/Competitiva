#include <iostream>
#include <string>
#include <set>
using namespace std ;
string deletechar(const string &v, int p) {
   string n ;
   n.resize(v.size()-1) ;
   int at = 0 ;
   for (int i=0; i<(int)v.size(); i++)
      if (i != p)
         n[at++] = v[i] ;
   return n ;
}
string insertchar(const string &v, int p, char c) {
   string n ;
   n.resize(v.size()+1) ;
   int at = 0 ;
   for (int i=0; i<(int)v.size(); i++) {
      if (i == p)
         n[at++] = c ;
      n[at++] = v[i] ;
   }
   if (p == (int)v.size())
      n[at++] = c ;
   return n ;
}
string changechar(const string &v, int p, char c) {
   string n(v) ;
   n[p] = c ;
   return n ;
}
int main() {
   string alpha, s ;
   cin >> alpha >> s ;
   set<string> result ;
   for (int i=0; i<(int)s.size(); i++)
      result.insert(deletechar(s, i)) ;
   for (auto c : alpha) {
      for (int i=0; i<(int)s.size(); i++)
         result.insert(changechar(s, i, c)) ;
      for (int i=0; i<=(int)s.size(); i++)
         result.insert(insertchar(s, i, c)) ;
   }
   result.erase(s) ;
   for (auto s : result)
      cout << s << endl ;
}
