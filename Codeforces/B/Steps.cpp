#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  
  long long int tx, ty, ax, ay, vx, vy, vectores;
  long double mx, my;
  long double INF = 1000000000000000;
  long long pasosTotales = 0;

  cin >> tx >> ty;
  cin >> ax >> ay;
  cin >> vectores;

  cout << endl;

  for(int i = 0; i < vectores; i++){
    
    cin >> vx >> vy;

    if(vx != 0){
      if(vx >0)
        mx = (tx-ax)/vx;
      if(vx <0)
        mx = (ax-1)/vx;
    }
    else
      mx = INF;
    
    if(vy != 0){

      if(vy > 0)
        my = (ty-ay)/vy;
      else
        my = (ay-1)/vy;
    }
    else
      my = INF;

    //cout << "ax: " << ax << "  " << "ay: " << ay << endl << mx << "  " << my << " Attempt " << i << endl << endl;
  
    if(fabs(mx) < fabs(my))
    {
      ax += abs(vx)*(int)floor(mx);
      ay += vy*abs((int)floor(mx));
      pasosTotales += abs((int)floor(mx));
    }
    else{
      ax += vx*abs((int)floor(my));
      ay += abs(vy)*(int)floor(my);
      pasosTotales += abs((int)floor(my));
    }
  }

  //cout << "ax: " << ax << "  " << "ay: " << ay << endl << endl;
  cout << pasosTotales;

  //map<long long int, long long int> leMape;
  //leMape.insert(pair <long long int, long long int>(op, i));
  return 0;
}
