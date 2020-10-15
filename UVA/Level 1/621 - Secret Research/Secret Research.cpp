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
  int cases;
  string caso;
  bool fallido, negativo;
  cin >> cases;
  
  FOR(n, 0, cases){
    cin >> caso;
      
    if(caso.size() >= 2){
      fallido = (caso[0] == '9' and caso[caso.size() - 1] == '4');
      negativo = (caso[caso.size() - 1] == '5' and caso[caso.size() - 2] == '3');
    }
    else{
      fallido = false;
      negativo = false;
    }
    
    if(caso == "4" or caso == "78" or caso == "1")
      cout << "+\n"; // positivo
    else if(negativo)
      cout << "-\n"; // negativo
    else if(fallido)
      cout << "*\n"; // fallido
    else
      cout << "?\n"; // inconcluso
  }
  
	return 0;
}
