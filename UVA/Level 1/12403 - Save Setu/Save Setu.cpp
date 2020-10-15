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
  int amount = 0, aux, cases;
  string what;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> what;
    
    if(what == "report")
      cout << amount << "\n";
    else{
      cin >> aux;
      amount += aux;
    }
  }
  
	return 0;
}
