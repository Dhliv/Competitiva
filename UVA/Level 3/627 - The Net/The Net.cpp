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
  int n, pos, cont, qs, nodo, ori, dest, x, y;
  string ent, res;
  pair<string, int> p;
  
  while(cin >> n){
    cout << "-----\n";
    vector<vector<int> > grafo(n + 1);
    
    getline(cin, ent);
    FOR(i, 0, n){
      getline(cin, ent);
      FOR(j, 0, ent.size()){
        if(ent[j] == '-'){
          nodo = stoi(ent.substr(0, j));
          pos = j + 1;
          break;
        }
      }
      
      FOR(j, pos, ent.size()){
        if(ent[j] == ','){
          grafo[nodo].PB(stoi(ent.substr(pos, j - pos)));
          j++;
          pos = j;
        }
      }
      
      if(ent.size() - pos)
        grafo[nodo].PB(stoi(ent.substr(pos, ent.size() - pos)));
    }
    
    cin >> qs;
    deque<int> q;
    
    FOR(a, 0, qs){
      cin >> ori >> dest;
      vector<int> seen(n + 1, INF), dads(n + 1);
      q.PB(ori);
      seen[ori] = 0;
      
      while(!q.empty()){
        x = q.F();
        q.P_F();
        
        FOR(i, 0, grafo[x].size()){
          y = grafo[x][i];
          if(seen[y] == INF){
            seen[y] = seen[nodo] + 1;
            q.PB(y);
            dads[y] = x;
          }
        }
      }
      
      if(seen[dest] == INF) cout << "connection impossible\n";
      else{
        res = to_string(dest);
        while(dads[dest]){
          res = to_string(dads[dest]) + " " + res;
          dest = dads[dest];
        }
        
        cout << res << "\n";
      }
    }
  }
  
  return 0;
}
