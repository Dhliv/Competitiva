#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std ;
const double PI = 3.14159265358979 ;
double fixang(double a) {
   if (a < 0)
      a += PI ;
   if (a > PI)
      a -= PI ;
   return a ;
}
int main(int argc, char *argv[]) {
   int n ;
   cin >> n ;
   vector<double> x(n), y(n) ;
   for (int i=0; i<n; i++)
      cin >> x[i] >> y[i] ;
   vector<pair<double, int>> sortme ;
   vector<vector<int>> next ;
   vector<vector<double>> angs ;
   for (int i=0; i<n; i++) {
      sortme.clear() ;
      for (int j=0; j<n; j++)
         if (i != j) {
            double dy = y[j] - y[i] ;
            double dx = x[j] - x[i] ;
            if (dy < 0 || (dy == 0 && dx < 0)) {
               dy = - dy ;
               dx = - dx ;
            }
            sortme.push_back({atan2(dy, dx),j}) ;
         }
      sort(sortme.begin(), sortme.end()) ;
      vector<int> v(n) ;
      vector<double> ang(n) ;
      v[sortme[sortme.size()-1].second] = sortme[0].second ;
      ang[sortme[sortme.size()-1].second] =
                     fixang(sortme[0].first - sortme[sortme.size()-1].first) ;
      for (int j=0; j+1<(int)sortme.size(); j++) {
         v[sortme[j].second] = sortme[j+1].second ;
         ang[sortme[j].second] = fixang(sortme[j+1].first - sortme[j].first) ;
      }
      next.push_back(v) ;
      angs.push_back(ang) ;
   }
   vector<vector<char> > seen ;
   for (int i=0; i<n; i++)
      seen.push_back(vector<char>(n)) ;
   int r = 0 ;
   for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
         if (i != j && !seen[i][j]) {
            vector<int> cnts(n) ;
            int ii = i ;
            int jj = j ;
            double totspin = 0 ;
            while (1) {
               cnts[ii]++ ;
               seen[ii][jj] = 1 ;
               int kk = next[ii][jj] ;
               totspin += angs[ii][jj] ;
               jj = ii ;
               ii = kk ;
               if (ii == i && jj == j && totspin >= 1.5 * PI)
                  break ;
            }
            for (auto v : cnts)
               r = max(r, v) ;
         }
   cout << r << endl ;
}
