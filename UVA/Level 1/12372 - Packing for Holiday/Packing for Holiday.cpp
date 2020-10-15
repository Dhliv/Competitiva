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
  int cases, l, w, h;
  cin >> cases;
  
  FOR(n, 0, cases){
    cout << "Case " << n+1 << ": ";
    cin >> l >> w >> h;
    
    if(l <= 20 and w <= 20 and h <= 20)
      cout << "good\n";
    else
      cout << "bad\n";
  }
  
	return 0;
}
