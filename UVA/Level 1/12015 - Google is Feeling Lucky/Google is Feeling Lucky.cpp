#include <bits/stdc++.h>
#define INF 1000000000
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
  int cases, ent, igual, mayor;
  string page;
  cin >> cases;
  
  FOR(a, 0, cases){
    cout << "Case #" << a+1 << ":\n";
    igual = 0;
    vector<int> orden;
    vector< pair<int, string> > store;
    
    FOR(i, 0, 10){
      cin >> page >> ent;
      orden.PB(ent);
      store.PB(MP(ent, page));
    }
    
    sort(orden.begin(), orden.end());
    mayor = orden[orden.size()-1];
    
    FOR(i, 0, 10){
      if(mayor == store[i].first)
        cout << store[i].second << "\n";
    }
  }
  
  return 0;
}