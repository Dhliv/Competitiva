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
	int posO, first, second, third, acumulado, tick = 9;

  while(cin >> posO >> first >> second >> third, posO+first+second+third){
    acumulado = 720;

    if(posO < first and first != posO){ 
      acumulado += (40 + posO - first)*tick;
    }
    else if(first != posO){
      acumulado += (posO - first)*tick;
    }
    
    acumulado += 360;

    if(first < second and first != second){
      acumulado += (second - first)*tick;
    }
    else if(first != second){
      acumulado += (40 - first + second)*tick;
    }

    if(second < third and second != third){
      acumulado += (40 + second - third)*tick;
    }
    else if(second != third){
      acumulado += (second - third)*tick;
    }

    cout << acumulado << "\n";
  }
  
	return 0;
}
