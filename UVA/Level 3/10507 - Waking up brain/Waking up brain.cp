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
  int n, m, x, y, year;
  bool wake;
  string ent, aw;
  
  while(cin >> n >> m >> aw){
    vector<int> seen(n), sum(n);
    vector<vector<int> > grafo(n, vector<int> (n));
    map<char, int> id;
    
    FOR(i, 0, m){
      cin >> ent;
      if(id.find(ent[0]) == id.end()){
        x = id.size();
        id.insert(MP(ent[0], x));
      }else x = id[ent[0]];
      
      if(id.find(ent[1]) == id.end()){
        y = id.size();
        id.insert(MP(ent[1], y));
      }else y = id[ent[1]];
      
      grafo[x][y] = 1;
      grafo[y][x] = 1;
    }
    
    deque<int> p, next;
    FOR(i, 0, aw.size()){
      if(id.find(aw[i]) == id.end()){
        x = id.size();
        id.insert(MP(aw[i], x));
      }else x = id[aw[i]];
      seen[x] = 1;
      sum[x] = 3;
      p.PB(x);
    }
    
    year = 0;
    while(true){
      while(!p.empty()){
        x = p.F();
        p.P_F();
        
        FOR(i, 0, n){
          if(grafo[x][i]){
            if(seen[i]) continue;
            sum[i]++;
            if(sum[i] >= 3){
              seen[i] = 1;
              next.PB(i);
            }
          }
        }
      }
      
      if(next.empty()) break;
      swap(next, p);
      year++;
    }
    
    wake = true;
    FOR(i, 0, n) if(seen[i] == 0) wake = false;
    
    if(wake) cout << "WAKE UP IN, " << year << ", YEARS\n";
    else cout << "THIS BRAIN NEVER WAKES UP\n";
  }
  
  return 0;
}