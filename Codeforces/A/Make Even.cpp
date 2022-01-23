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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  string n;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n;
    if(!(n[n.size() - 1] - '0' & 1)) cout << "0\n";
    else if(!(n[0] - '0' & 1)) cout << "1\n";
    else{
      bool able = false;
      FOR(i, 0, n.size()){
        if(!(n[i] - '0' & 1)){
          able = true;
          break;
        }
      }

      if(able) cout << "2\n";
      else cout << "-1\n";
    }
  }
  
  return 0;
}
