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
  int cases, altura, before, altos, bajos, muros;
  cin >> cases;
  
  FOR(i, 0, cases){
    cout << "Case " << i+1 << ": ";
    cin >> muros >> before;
    altos = 0, bajos = 0;
    
    FOR(j, 1, muros){
      cin >> altura;
      
      if(altura > before)
        altos++;
      else if(altura < before)
        bajos++;
        
      before = altura;
    }
    
    cout << altos << " " << bajos << "\n";
  }
  
	return 0;
}
