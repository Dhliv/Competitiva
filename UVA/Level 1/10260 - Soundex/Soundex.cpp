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

int main() {
	string palabra;
  int valores[26] = {0}, aux;
  valores['B' - 'A'] = 1;
  valores['P' - 'A'] = 1;
  valores['F' - 'A'] = 1;
  valores['V' - 'A'] = 1;
  valores['C' - 'A'] = 2;
  valores['G' - 'A'] = 2;
  valores['J' - 'A'] = 2;
  valores['K' - 'A'] = 2;
  valores['Q' - 'A'] = 2;
  valores['X' - 'A'] = 2;
  valores['Z' - 'A'] = 2;
  valores['S' - 'A'] = 2;
  valores['D' - 'A'] = 3;
  valores['T' - 'A'] = 3;
  valores['L' - 'A'] = 4;
  valores['M' - 'A'] = 5;
  valores['N' - 'A'] = 5;
  valores['R' - 'A'] = 6;
  //BOBBBBT
  while(cin >> palabra){
    FOR(i, 0, palabra.size()){
      aux = valores[palabra[i] - 'A']; // 3
      if(aux){
        if((i+1 < palabra.size() and valores[palabra[i+1] - 'A'] != aux) or i+1 == palabra.size())
          cout << aux;
      }
    }
    cout << "\n";
  }
  //-> 11
	return 0;
}
