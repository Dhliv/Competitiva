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
  int cases, colum, x, y;
  bool different;
  cin >> cases;
  
  FOR(n, 0, cases){
    cin >> colum;
    vector<int> v(colum);
    different = false;
    FOR(i, 0, colum){
      cin >> x >> y;
      v[i] = (abs(x - y) + 1);
    }
    
    FOR(i, 1, colum){
      if(v[i] != v[i-1])
        different = true;
    }
    
    if(different)
      cout << "no\n";
    else
      cout << "yes\n";
      
    if(n+1 != cases)
      cout << "\n";
  }
  
	return 0;
}
