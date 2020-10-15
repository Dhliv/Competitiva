#include <bits/stdc++.h>
#define INF 2000000000
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

int main(){
  string ent, ans;
  int cases;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> ent;
    ans = "";
    ans += ent.substr(0, 2);
    
    FOR(i, 3, ent.size()){
      if(i%2)
        ans += ent[i];
    }
    
    cout << ans + "\n";
  }

  return 0;
}