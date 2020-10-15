#include <bits/stdc++.h>
#define LINF LLONG_MAX
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORI(i, a, b) for(int i = a; i >= b; i--)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int n, k, w, sub, dad, v;
  cin >> n >> k;
  vector<vector<int> > grafo(n + 1);
  vector<int> dads(n + 1, 0), supe(n+1, INF);
  
  FOR(i, 1, k + 1){
    cin >> w;
    FOR(j, 0, w){
      cin >> sub;
      grafo[i].PB(sub);
      dads[sub]++;
    }
  }
  
  deque<int> sup, bas;
  
  FOR(i, 1, n+1){
    if(dads[i] == 0 and grafo[i].size()){
      sup.PB(i);
      bas.PB(i);
    }
  }
  dad = sup[0];
  supe[dad] = 0;
  
  while(!sup.empty()){
    sub = sup.F();
    sup.P_F();
    
    FOR(i, 0, grafo[sub].size()){
      v = grafo[sub][i];
      dads[v]--;
      if(dads[v] == 0){
        sup.PB(v);
        bas.PB(v);
      }
    }
  }
  
  w = 0;
  while(!bas.empty()){
    v = bas.F();
    bas.P_F();
    
    supe[v] = w;
    w = v;
  }
  
  FOR(i, 1, n+1){
    if(supe[i] != INF) cout << supe[i] << "\n";
    else cout << dad << "\n";
  }
  
  return 0;
}