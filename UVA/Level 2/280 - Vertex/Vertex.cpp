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
  int n, ori, dest, id, tam, x, y;
  pair<int, int> ret;
  
  while(cin >> n, n){
    vector<vector<int> > grafo(n + 1);
    
    while(cin >> id, id){
      while(cin >> dest, dest) grafo[id].PB(dest);
    }
    
    cin >> tam;
    deque<int> q, ans;
    
    FOR(i, 0, tam){
      cin >> id;
      vector<int> seen(n + 1), vistos(n + 1);
      q.PB(id);
      seen[id] = 1;
      
      while(!q.empty()){
        x = q.F();
        q.P_F();
        
        FOR(j, 0, grafo[x].size()){
          y = grafo[x][j];
          if(vistos[y] == 0) vistos[y] = 1;
          if(seen[y] == 0){
            seen[y] = 1;
            q.PB(y);
          }
        }
      }
      
      FOR(i, 1, n + 1) if(!vistos[i]) ans.PB(i);
      cout << ans.size();
      while(!ans.empty()){ 
        cout << " " << ans.F();
        ans.P_F();
      }
      
      cout << "\n";
    }
  }
  
  return 0;
}