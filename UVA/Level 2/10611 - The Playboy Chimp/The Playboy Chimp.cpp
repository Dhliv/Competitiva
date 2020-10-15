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
typedef map<ll,int> mapa;

int main() {
	mapa leMape;
	ll chimps, Q, aux;
	cin >> chimps;
	
	FOR(i, 0, chimps){
	  cin >> aux;
	  leMape.insert(MP(aux, 0));
	}
	cin >> Q;
	
	FOR(i, 0, Q){
	  cin >> aux;
	  bool wasnt = false;
	  if(leMape.find(aux) == leMape.end()){
	    leMape.insert(MP(aux, 0));
	    wasnt = true;
	  }
	    
	  if(leMape.find(aux) == leMape.begin())
	    cout << "X ";
	  else
	    cout << (--leMape.find(aux))->first << " ";
	    
	  if(leMape.find(aux) != (--leMape.end()))
	    cout << (++leMape.find(aux))->first << "\n";
	  else
	    cout << "X\n";
	    
	  if(wasnt)
	    leMape.erase(leMape.find(aux));
	}
	
	return 0;
}
