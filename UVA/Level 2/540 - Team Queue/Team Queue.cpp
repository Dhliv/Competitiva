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
  int t, n, p, team, cont = 1;
  string ent;
  
  while(cin >> t, t){
    map<int, int> eqi;
    vector<deque<int> > filas(t);
    vector<int> infil(t);
    deque<int> orden;
    
    FOR(i, 0, t){
      cin >> n;
      FOR(j, 0, n){
        cin >> p;
        eqi.insert(MP(p, i));
      }
    }
    
    cout << "Scenario #" << cont++ << "\n";
    
    while(cin >> ent, ent != "STOP"){
      if(ent == "ENQUEUE"){
        cin >> p;
        team = eqi.find(p)->s;
        if(!infil[team]){
          infil[team] = 1;
          orden.PB(team);
        }
        filas[team].PB(p);
      }else{
        cout << filas[orden.F()].F() << "\n";
        filas[orden.F()].P_F();
        
        if(filas[orden.F()].empty()){
          infil[orden.F()] = 0;
          orden.P_F();
        }
      }
    }
    
    cout << "\n";
  }
  
  return 0;
}
