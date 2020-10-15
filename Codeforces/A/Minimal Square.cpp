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
  int cases, a, b;
  cin >> cases;
  
  FOR(i, 0, cases){
    cin >> a >> b;
    if(2*a >= b and a <= b)
      cout << 4*a*a << "\n";
    else if(2*b >= a and b <= a)
      cout << 4*b*b << "\n";
    else if(a < b)
      cout << b*b << "\n";
    else
      cout << a*a << "\n";
      
  }
  
	return 0;
}
