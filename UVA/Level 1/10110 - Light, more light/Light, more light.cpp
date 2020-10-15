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
	ll num;
	double raiz, aux;
	
	while(cin >> num, num){
	  raiz = sqrt(num);
	  aux = floor(raiz);
	  
	  if(raiz == aux)
	    cout << "yes\n";
	  else
	    cout << "no\n";
	}
	
	return 0;
}
