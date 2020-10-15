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

int cir(punto cen, punto p){
  return ((p.x - cen.x)*(p.x - cen.x) + (p.y - cen.y)*(p.y - cen.y));
}

int main(){
  int r, s, a, b, rc;
  punto cen, izqd, izqu, derd, deru;
  cin >> a >> b >> r;
  cen(a, b);
  cin >> a >> b >> s;
  izqd(a, b);
  izqu(a, b + s);
  derd(a + s, b);
  deru(a + s, b + s);
  bool able = false;
  rc = r*r;
  
  if(cir(cen, izqd) < rc) able = true;
  else if(cir(cen, izqu) < rc) able = true;
  else if(cir(cen, deru) < rc) able = true;
  else if(cir(cen, derd) < rc) able = true;
  
  if((cen.y + r) >= deru.y and derd.y >= (cen.y - r)){
    if((cen.x + r) >= derd.x and izqu.x >= (cen.x - r)) able = true; // Sq dentro del C
  }else if((cen.y + r) <= deru.y and derd.y <= (cen.y - r)){
    if((cen.x + r) <= derd.x and izqu.x <= (cen.x - r)) able = true; // C dentro del Sq
  }else if(izqd.y >= (cen.y - r) and izqd.y < (cen.y + r)){
    if(izqd.x <= (cen.x - r) and derd.x >= (cen.x + r)) able = true;
  }else if(deru.y <= (cen.y + r) and deru.y > (cen.y - r)){
    if(izqd.x <= (cen.x - r) and derd.x >= (cen.x + r)) able = true;
  }else if(derd.x > (cen.x - r) and derd.x <= (cen.x + r)){
    if(deru.y >= (cen.y + r) and derd.y <= (cen.y - r)) able = true;
  }else if(izqd.x >= (cen.x - r) and izqd.x < (cen.x + r)){
    if(deru.y >= (cen.y + r) and derd.y <= (cen.y - r)) able = true;
  }
  
  if(able) cout << "2\n";
  else{
    if(cir(cen, izqd) == rc) able = true;
    else if(cir(cen, izqu) == rc) able = true;
    else if(cir(cen, deru) == rc) able = true;
    else if(cir(cen, derd) == rc) able = true;
    else if((cen.x + r) == izqd.x and (cen.y > izqd.y and cen.y < izqu.y)) able = true; // check
    else if((cen.x - r) == derd.x and (cen.y > izqd.y and cen.y < izqu.y)) able = true; // check
    else if((cen.y + r) == izqd.y and (cen.x > izqd.x and cen.x < derd.x)) able = true; // check
    else if((cen.y - r) == deru.y and (cen.x > izqd.x and cen.x < derd.x)) able = true; // check
    
    if(able) cout << "1\n";
    else cout << "0\n";
  }
  
  return 0;
}