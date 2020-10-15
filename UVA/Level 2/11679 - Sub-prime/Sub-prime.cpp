#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;
typedef map<string, int> mapa;

int main() {
  int banks, bonos, valor, deudor, cobrante;
  bool bailout;
  
  while(cin >> banks >> bonos, banks){
    vector<int> reservas(banks);
    bailout = false;
    
    FOR(i, 0, banks)
      cin >> reservas[i];
      
    FOR(i, 0, bonos){
      cin >> deudor >> cobrante >> valor;
      reservas[deudor-1] -= valor;
      reservas[cobrante-1] += valor;
    }
    
    FOR(i, 0, banks){
      if(reservas[i] < 0)
        bailout = true;
    }
    
    if(bailout)
      cout << "N\n";
    else
      cout << "S\n";
  }
  
	return 0;
}
