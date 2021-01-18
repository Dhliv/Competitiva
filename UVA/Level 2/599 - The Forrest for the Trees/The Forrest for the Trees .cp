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

using namespace std;

int main(){
  int cases, x, y, cont, n = 26, ac, tr;
  cin >> cases;
  string ent;
  getline(cin, ent);
  
  FOR(ab, 0, cases){
    vector<vector<int> > grafo(n);
    vector<int> seen(n), pres(n);
    
    while(getline(cin, ent)){
      if(ent[0] == '*') break;
      x = ent[1] - 'A';
      y = ent[3] - 'A';
      grafo[x].PB(y);
      grafo[y].PB(x);
    }
    
    getline(cin, ent);
    FOR(i, 0, ent.size()){
      if(ent[i] != ',') pres[ent[i] - 'A'] = 1;
    }
    
    ac = tr = 0;
    deque<int> q;
    FOR(i, 0, n){
      if(pres[i] and !seen[i]){
        q.PB(i);
        seen[i] = 1;
        cont = 1;
        
        while(!q.empty()){
          x = q.F();
          q.P_F();
          
          FOR(j, 0, grafo[x].size()){
            y = grafo[x][j];
            if(!seen[y]){
              seen[y] = 1;
              q.PB(y);
              cont++;
            }
          }
        }
        
        if(cont == 1) ac++;
        else tr++;
      }
    }
    
    cout << "There are " << tr << " tree(s) and " << ac << " acorn(s).\n";
  }
  
  return 0;
}