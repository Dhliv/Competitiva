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
	ll cases, ingr, recipes, budget, aux2, costo, elements;
	string name, aux1, rece;
	char letra;
	cin >> cases;
	getline(cin, aux1);
	
	FOR(n, 0, cases){
	  getline(cin, name);
	  cin >> ingr >> recipes >> budget;
	  mapa recetas, ingredientes;
	  vector < pair<ll, string> > v;
	  
	  FOR(i, 0, ingr){
	    cin >> aux1 >> aux2;
	    ingredientes.insert(MP(aux1, aux2));
	  }
	  
	  FOR(i, 0, recipes){
	    getline(cin, aux1);
	    getline(cin, rece);
	    cin >> elements;
	    costo = 0;
	    FOR(j, 0, elements){
	      cin >> aux1 >> aux2;
	      costo += aux2 * ingredientes.find(aux1)->second;
	    }
	    if(costo <= budget){
	      recetas.insert(MP(rece, costo));
	    }
	  }
	  
	  FOR(i, 0, name.size()){
	    if(0 < name[i] - 'a' < 26)
	      letra = toupper(name[i]);
	    cout << letra;
	  }
	  cout << "\n";
	  
	  forit(x, recetas)
	    v.PB(MP(x->second, x->first));
	  
	  if(v.size()){
  	  sort(v.begin(), v.end());
  	  FOR(i, 0, v.size())
  	    cout << v[i].second << "\n";
	  }else
	    cout << "Too expensive!\n";
	    
	  cout << "\n";
	  getline(cin, aux1);
	}
	
	return 0;
}
