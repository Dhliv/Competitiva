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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main(){
  int n, fac, x;
  bool pila, cola, pcola;
  
  while(cin >> n){
    deque<int> col, pil;
    priority_queue<int> p;
    pila = cola = pcola = true;
    
    FOR(i, 0, n){
      cin >> fac >> x;
      if(fac == 2){
        if(col.empty() and pil.empty() and p.empty()) pila = cola = pcola = false;
        else{
          if(cola){
            if(x == col.F()) col.P_F();
            else cola = false;
          }
          if(pila){
            if(x == pil.B()) pil.P_B();
            else pila = false;
          }
          if(pcola){
            if(x == p.top()) p.pop();
            else pcola = false;
          }
        }
      }else{
        col.PB(x);
        pil.PB(x);
        p.push(x);
      }
    }
    
    if(!cola and !pila and !pcola) cout << "impossible\n";
    else if((cola + pila + pcola) > 1) cout << "not sure\n";
    else{
      if(cola) cout << "queue\n";
      else if(pila) cout << "stack\n";
      else cout << "priority queue\n";
    }
  }

  return 0;
}
