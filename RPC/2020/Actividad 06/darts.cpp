#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define For(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

double tam, w;

int comp(double sq, double r1, double r2, double r3){

  if(sq <= r1) return 1;
  if(sq >= r1 and sq <=r2) return 2;
  if(sq >= r2 and sq <= r3) return 3;

  return 0;
}

double solve(double degree){
  for(int i=1; i<w+1; i++){
    if((i-1)*tam<=degree and degree<=i*tam) return i;
  }
}

double cuad(double px, double py){
  if(px >= 0.0 and py >= 0.0) return 0.0;
  if(px <= 0.0 and py >= 0.0) return 0.5;
  if(px <= 0.0 and py <= 0.0) return 1.0;
  if(px >= 0.0 and py <= 0.0)return 1.5;
  return 0.0;
}

int main(){
  double r1,r2,r3, score, sq, px, py, ang, radianes;
  ll n, cases;
  int accion;
  cin >> cases;
  For(casos,0,cases){

    score=0;
    sq = 0;
    accion =0;
    cin >> w;
    tam = 2*M_PI/w;
    cin >> r1>>r2>>r3;
    cin >> n;
    For(i,0,n){
      cin >> px >> py;
      
      sq = sqrt(pow(px,2)+pow(py,2));
      accion = comp(sq,r1,r2,r3);
      
      if(accion == 1){
        score+=50;
      }else if(accion == 2){
        ang = cuad(px, py);
        if(ang == 0.5 or ang == 1.5) radianes = (M_PI*0.5) - abs(atan(py/px));
        else radianes = abs(atan(py/px));
        ang *= M_PI;
        score+= 2*solve(ang+radianes);
      }else if(accion == 3){ 
        ang = cuad(px, py);
        if(ang == 0.5 or ang == 1.5) radianes = (M_PI*0.5) - abs(atan(py/px));
        else radianes = abs(atan(py/px));
        ang *= M_PI;
        score+= solve(ang+radianes);
      }
    }
    cout << score << endl;
  }
  return 0;
}


/*
// 1 == r1
// 2 == r2
// 3 == r3

double tam, w;
int comp(double sq, double r1, double r2, double r3){

  if(sq<=r1) return 1;
  if(sq=>r1 and sq<=r2) return 2;
  if(sq >= r2 and sq<= r3) return 3;

  return 0;
}

double solve(double degree){
  for(int i=1; i<w+1; i++){
    if((i-1)*tam<degree and degree<i*tam) return i;
  }
}

int main(){

  cin >> cases;
  For(casos,0,cases){
    cin >> w;
    tam = 2*pi/w;
    cin >> r1>>r2>>r3;
    cin >> n;
    For(i,0,n){
      cin >> px >> py;
      sq = sqrt(px^2+py^2);
      accion = comp(sq,r1,r2,r3);
      if(accion == 1){
        score+=50;
      }else if(accion == 2){
        score+= 2*solve(atan(px/py));
      }else if(accion == 3) score+= solve(atan(px/py));

    }
  }
  return 0;
}

*/




