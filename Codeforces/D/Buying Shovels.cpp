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

int main() {
  int cases, n, k, aux;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> n >> k;
    
    if(n%k){
      aux = 1;
      FOR(i, 1, sqrt(n)+1){
        if(n%i == 0 and i <= k){
          if(n/i <= k and n/i > aux)
            aux = n/i;
            
          if(i > aux)
            aux = i;
        }
      }
      cout << n/aux << "\n";
    }else
      cout << n/k << "\n";
  }
  
	return 0;
}
