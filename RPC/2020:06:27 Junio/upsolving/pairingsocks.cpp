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
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)

using namespace std;

int main() {
  int n, ans;
  cin >> n;
  deque<int> pila(2*n), pilax;


  FOR(i, 0, 2*n)
    cin >> pila[i];

  ans = 0;
  while(pila.size() + pilax.size()){
    if(!pila.empty() and !pilax.empty()){
      if(pila.B() == pilax.B()){
        pila.P_B();
        pilax.P_B();
      }else{
        pilax.PB(pila.B());
        pila.P_B();
      }
    }else{
      if(pila.empty())
        break;
      else{
        pilax.PF(pila.B());
        pila.P_B();
      }
    }
    ans++;
  }
  if(pila.empty() and pilax.empty())
    cout << ans << "\n";
  else
    cout << "impossible\n";

	return 0;
}