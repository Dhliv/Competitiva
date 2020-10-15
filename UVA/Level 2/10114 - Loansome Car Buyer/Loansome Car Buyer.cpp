#include <bits/stdc++.h>
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
  int meses, depreciacion, mes, total;
  double depositado, deuda, coche, tasa, pagado, aporte;
  bool out;
  cout.precision(20);
  
  while(cin >> meses >> depositado >> deuda >> depreciacion){
    if(meses < 0 or deuda < 0.0 or depositado < 0.0 or depreciacion < 0) break;
    
    coche = deuda + depositado;
    aporte = deuda/meses;
    pagado = 0;
    out = false;
    total = -1;
    vector< pair<int, double> > store;
    
    FOR(i, 0, depreciacion){
      cin >> mes >> tasa;
      store.PB(MP(mes, tasa));
    }
    
    FOR(i, 1, store.size()){
      FOR(j, 0, store[i].first - store[i-1].first){
        coche *= (1.0 - store[i-1].second);
        total++;
        
        if(deuda < coche){
          out = true;
          if(total == 1)
            cout << "1 month\n";
          else
            cout << total << " months\n";
          break;
        }else{
          deuda -= aporte;
        }
      }
      if(out)
        break;
    }
    
    if(!out){
      FOR(i, store[store.size()-1].first, meses+1){
        coche *= (1.0 - store[store.size()-1].second);
        total++;
        
        if(deuda < coche){
          if(total == 1)
            cout << "1 month\n";
          else
            cout << total << " months\n";
          break;
        }else{
          deuda -= aporte;
        }
      }
    }
  }
  
	return 0;
}
