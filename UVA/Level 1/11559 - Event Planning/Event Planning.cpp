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
  int parts, budget, hotels, weeks, best, costo, disponible, aux;
  
  while(cin >> parts >> budget >> hotels >> weeks){
    best = INF;
    if(parts <= 0 or budget <= 0 or hotels <= 0 or weeks <= 0) break;
    
    FOR(i, 0, hotels){
      disponible = 0;
      cin >> costo;
      FOR(j, 0, weeks){
        cin >> aux;
        if(aux > disponible)
          disponible = aux;
      }
      aux = costo*parts;
      if(disponible >= parts and aux <= budget and aux <= best)
        best = aux;
    }
    
    if(best == INF)
      cout << "stay home\n";
    else
      cout << best << "\n";
  }
  
	return 0;
}
