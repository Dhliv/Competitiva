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
  string ent, res;
  int tam, nodo, x;
  
  while(cin >> ent){
    vector<string> orden;
    vector<vector<int> > grafo(26);
    vector<int> dirs(26);
    set<int> apar;
    
    orden.PB(ent);
  
    while(cin >> ent, ent != "#") orden.PB(ent);
    
    FOR(i, 0, orden.size()){
      FOR(j, 0, orden[i].size()){
        if(apar.find(orden[i][j] - 'A') == apar.end()) apar.insert(orden[i][j] - 'A');
      }
    }
    
    FOR(i, 1, orden.size()){
      tam = min(orden[i].size(), orden[i - 1].size());
      
      FOR(j, 0, tam){
        if(orden[i][j] != orden[i - 1][j]){
          grafo[orden[i - 1][j] - 'A'].PB(orden[i][j] - 'A');
          dirs[orden[i][j] - 'A']++;
          break;
        }
      }
    }
    
    deque<int> q;
    
    FOR(i, 0, 26){
      if(dirs[i] == 0 and apar.find(i) != apar.end()){
        q.PB(i);
      }
    }
    
    res = "";
    
    while(!q.empty()){
      nodo = q.F();
      q.P_F();
      res += (char)(nodo + 'A');
      
      FOR(i, 0, grafo[nodo].size()){
        x = grafo[nodo][i];
        dirs[x]--;
        if(dirs[x] == 0) q.PB(x);
      }
    }
    
    cout << res + "\n";
  }
  
  return 0;
}
