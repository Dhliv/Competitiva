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
  int n, treats, due, count = 1, aux;
  
  while(cin >> n, n){
    cout << "Case " << count << ": ";
    treats = 0, due = 0;
    
    FOR(i, 0, n){
      cin >> aux;
      if(aux)
        treats++;
      else
        due++;
    }
    cout << treats - due << "\n";
    count++;
  }
  
	return 0;
}
