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
typedef map<string,int> mapa;

int main() {
	int frosh, ini, mayor;
	string in, aux;
	mapa leMape;
	map<mapa, int> mapita;
	
	while(cin >> frosh, frosh){
	  FOR(i, 0, frosh){
	    mayor = 0;
	    
	    FOR(j, 0, 5){
	      cin >> aux;
	      leMape.insert(MP(aux, 1));
	    }
	    
	    if(mapita.find(leMape) == mapita.end())
	      mapita.insert(MP(leMape, 1));
	    else
	      mapita[leMape]++;
	      
	    leMape.clear();
	  }
	    
	  
	  forit(x, mapita){
	    if(x->second > mayor)
	      mayor = x->second;
	  }
	  int cont = 0;
	  
	  forit(x, mapita){
	    if(x->second == mayor)
	      cont++;
	  }
	  
	  cout << mayor*cont << "\n";
	  mapita.clear();
	}
	
	return 0;
}
