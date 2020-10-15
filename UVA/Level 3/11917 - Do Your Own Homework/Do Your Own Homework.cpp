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
  int cases, D, materias, aux;
  string mat;
  cin >> cases;

  FOR(n, 0, cases){
    mapa leMape;
    cin >> materias;
    cout << "Case " << n+1 << ": ";

    FOR(i, 0, materias){
      cin >> mat >> aux;
      leMape.insert(MP(mat,aux));
    }
    cin >> D >> mat;

    //RESOLUCION
    if(leMape.find(mat) != leMape.end()){
      aux = leMape.find(mat)->second;
      if(aux <= D)
        cout << "Yesss";
      else if(aux <= D+5)
        cout << "Late";
      else
        cout << "Do your own homework!";
    }else
      cout << "Do your own homework!";

    cout << endl;
  }
  
	return 0;
}
