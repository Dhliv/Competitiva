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

int main(){
  int n, lim, valor = 0, ans = 0, aux;
  cin >> n >> lim;
  
  FOR(i, 0, n){
    cin >> aux;
    valor += aux;
  }
  
  aux = abs(valor);
  
  if(aux == 0) cout << 0 << "\n";
  else if(lim >= aux) cout << 1 << "\n";
  else{
    ans += aux/lim;
    if(aux%lim) ans++;
    cout << ans << "\n";
  }
  
  return 0;
}