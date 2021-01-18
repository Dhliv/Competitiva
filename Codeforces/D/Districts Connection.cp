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
  int cases, x, y, nodo, n;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> n;
    vector<int> dat(n);
    map<int, vector<int> > pos;
    
    FOR(i, 0, n){
      cin >> dat[i];
      if(pos.find(dat[i]) == pos.end()) pos[dat[i]] = vector<int> (1, i);
      else pos[dat[i]].PB(i);
    }
    
    if(pos.size() > 1){
      cout << "YES\n";
      x = pos.begin()->s[0] + 1;
      
      for(auto nodo: pos){
        if(nodo.f == pos.begin()->f) continue;
        FOR(i, 0, nodo.s.size()){
          cout << x << " " << nodo.s[i] + 1 << "\n";
        }
      }
      
      x = (++pos.begin())->s[0] + 1;
      dat = pos.begin()->s;
      FOR(i, 1, dat.size()){
        cout << x << " " << dat[i] + 1 << "\n";
      }
    }else cout << "NO\n";
  }
  
  return 0;
}