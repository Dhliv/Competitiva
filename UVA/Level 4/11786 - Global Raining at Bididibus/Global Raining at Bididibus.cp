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
  int cases, ans;
  string ent;
  cin >> cases;
  getline(cin, ent);
  
  FOR(a, 0, cases){
    deque<int> q;
    getline(cin, ent);
    ans = 0;
    
    FOR(i, 0, ent.size()){
      if(ent[i] == '\\') q.PB(i);
      else if(ent[i] == '/' and !q.empty()){
        ans += (i - q.B());
        q.P_B();
      }
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}