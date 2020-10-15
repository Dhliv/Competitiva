#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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
  int t, ax, n, mini;
  bool able;
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    vector<int> ori(n), org;
    able = true;
    
    FOR(i, 0, n) cin >> ori[i];
    org = ori;
    sort(org.begin(), org.end());
    mini = org[0];
    
    FOR(i, 0, n){
      if(org[i] != ori[i] and ori[i]%mini){
        able = false;
        break;
      }
    }
    
    if(able) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}