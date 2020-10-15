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

bool able;

ll solve(){
  ll wl, wr, dl, dr;
  cin >> wl >> dl >> wr >> dr;
  
  if(wl == 0 and wr == 0){
    wl = solve();
    wr = solve();
  }else if(wl == 0){
    wl = solve();
  }else if(wr == 0){
    wr = solve();
  }
  
  if(wl*dl != wr*dr) able = false;
  
  return wl + wr;
}

int main(){
  int cases;
  ll aux;
  string ent;
  pair<int, int> num;
  cin >> cases;
  
  FOR(i, 0, cases){
    if(i) cout << "\n";
    able = true;
    aux = solve();
    
    if(able) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}