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

struct wind{
  punto up, down;
  
  void operator() (int a, int b, int c, int d){
    down(a, b);
    up(c, d);
  }
};

int main(){
  int cases, a, b, c, d;
  wind uno, dos;
  cin >> cases;
  punto p1, p2;
  
  FOR(caso, 0, cases){
    if(caso) cout << "\n";
    
    cin >> a >> b >> c >> d;
    uno(a, b, c, d);
    cin >> a >> b >> c >> d;
    dos(a, b, c, d);
    
    a = max(uno.down.x, dos.down.x);
    b = max(uno.down.y, dos.down.y);
    c = min(uno.up.x, dos.up.x);
    d = min(uno.up.y, dos.up.y);
      
    if(a < c and b < d) cout << a << " " << b << " " << c << " " << d << "\n";
    else cout << "No Overlap\n";
  }
  
  return 0;
}