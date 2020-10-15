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
  int cases, ath, min, aux;
  cin >> cases;
  
  FOR(n, 0, cases){
    cin >> ath;
    vector<int> v(ath);
    min = 1000000000;
    
    FOR(i, 0, ath)
      cin >> v[i];
      
    sort(v.begin(), v.end());
    
    FOR(i, 1, v.size()){
      aux = v[i] - v[i-1];
      if(aux < min)
        min = aux;
    }
    
    cout << min << "\n";
  }
  
	return 0;
}
