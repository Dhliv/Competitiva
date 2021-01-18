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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

struct point{
  int x, y;
  void operator() (int a, int b){
    x = a;
    y = b;
  }
};

int main(){
  int n, a, b, down = INF, up = MINF, izq = INF, der = MINF;
  ll ans = 0;
  cin >> n;
  
  point uno, dos, primero;
  cin >> a >> b;
  uno(a, b);
  primero(a, b);
  
  FOR(i, 1, n){
    cin >> a >> b;
    dos(a, b);
    
    if(dos.x == uno.x){
      a = max(uno.y, dos.y);
      b = min(uno.y, dos.y);
      ans += a - b;
      up = max(a, up);
      down = min(b, down);
    }
    else{
      a = max(uno.x, dos.x);
      b = min(uno.x, dos.x);
      ans += a - b;
      izq = min(b, izq);
      der = max(a, der);
    }
    
    uno = dos;
  }
  
  if(primero.x == uno.x){
    a = max(uno.y, primero.y);
    b = min(uno.y, primero.y);
    ans += a - b;
    up = max(a, up);
    down = min(b, down);
  }else{
    a = max(uno.x, primero.x);
    b = min(uno.x, primero.x);
    ans += a - b;
    izq = min(b, izq);
    der = max(a, der);
  }
  
  ans -= (2*(up - down) + 2*(der - izq));
  cout << ans << "\n";
  
  return 0;
}