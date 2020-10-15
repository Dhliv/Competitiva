#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

struct punto{
  int x, y;
  
  void operator() (int a, int b){
    x = a;
    y = b;
  }
};

int main(){
  int x, y;
  cout.precision(8);
  punto ini1, ini2, fin1, fin2;
  ld m1, m2, ans, epsi = 1e-6, area = 0.0, equis;
  bool r1 = true;
  pair<ld, ld> inter;
  inter = MP(0.0, 0.0);
  
  cin >> x >> y;
  ini1(x, y);
  cin >> x >> y;
  fin1(x, y);
  cin >> x >> y;
  ini2(x, y);
  cin >> x >> y;
  fin2(x, y);
  
  m1 = (ini1.y - fin1.y)/(1.0*(ini1.x - fin1.x));
  m2 = (ini2.y - fin2.y)/(1.0*(ini2.x - fin2.x));
  
  inter.f = 1.0;
  
  ans = m2 - m1;
  
  if(0){}
  else{
    inter.f = (ini1.y*1.0 - 1.0*ini2.y + m2*ini2.x - m1*ini1.x)/ans;
    
    
    if(inter.f + epsi >= ini1.x*1.0 and inter.f - epsi <= fin1.x*1.0 ){
      if(inter.f - epsi <= ini2.x*1.0 and inter.f + epsi >= fin2.x*1.0){
        inter.s = ini1.y*1.0 + m1*(inter.f - ini1.x);
        
        if(fin1.y > fin2.y){
          y = fin2.y;
          x = fin2.x;
          r1 = false;
        }else{
          y = fin1.y;
          x = fin1.x;
        }
        
        area += fabs((y*1.0 - inter.s)*(x*1.0 - inter.f)/2.0);
        
        if(r1) equis = (y*1.0 - ini2.y*1.0 + m2*ini2.x)/m2;
        else equis = (y*1.0 - ini1.y*1.0 + m1*ini1.x)/m1;
        
        area += fabs((y*1.0 - inter.s)*(equis - inter.f)/2.0);
        
        cout << fixed << area << "\n";
      }else cout << "0.0\n";
    }else cout << "0.0\n";
  }
  
  return 0;
}