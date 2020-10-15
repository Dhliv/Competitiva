#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define ld long double
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, n, m;
  bool d1, all;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n >> m;
    vector<vector<int> > l(2, vector<int> (2));
    all = d1 = false;
    
    FOR(i, 0, n){
      FOR(j, 0, 2){
        FOR(k, 0, 2) cin >> l[j][k];
      }
      
      all = all or ((l[0][0] == l[1][1]) and (l[0][1] == l[1][0]));
      d1 = d1 or (l[0][1] == l[1][0]);
    }
    
    if(m%2 or (!d1 and !all)) cout << "NO\n";
    else cout << "YES\n";
  }
  
  return 0;
}