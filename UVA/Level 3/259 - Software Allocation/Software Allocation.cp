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

int ft;

int bfs(vector<vector<int> > &grafo, int ori, int dest){
  int x, y;
  vector<int> seen(grafo.size(), INF);
  seen[ori] = 0;
  deque<int> q;
  q.PB(ori);
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      if(seen[y] > seen[x] + 1){
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return seen[dest];
}

int dfs(vector<vector<int> > &grafo, vector<vector<int> > &flows, int ori, int &dest, int act, int &path){
  int y, acum = act + 1, flujo = INF;
  
  FOR(i, 0, grafo[ori].size()){
    y = grafo[ori][i];
    if(acum == path and y != dest) continue;
    else if(acum == path){
      ft++;
      flows[ori][y] -= 1;
      flows[y][ori] += 1;
      if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
      if(flows[y][ori] == 1) grafo[y].PB(ori);
      return 1;
    }else{
      flujo = dfs(grafo, flows, y, dest, acum, path);
      if(flujo == 1){
        flows[ori][y] -= 1;
        flows[y][ori] += 1;
        if(flows[ori][y] == 0) grafo[ori].erase(grafo[ori].begin() + i);
        if(flows[y][ori] == 1) grafo[y].PB(ori);
        return 1;
      }
    }
  }
  
  return flujo;
}

int main(){
  int n, x, y, f, s = 36, t = 37, sum;
  string ent;
  char k;
  map<char, int> ids;
  map<int, char> names;
  
  FOR(i, 0, 26){
    k = 'A' + i;
    ids.insert(MP(k, i));
    names.insert(MP(i, k));
  }
  
  FOR(i, 0, 10){
    k = '0' + i;
    ids.insert(MP(k, ids.size()));
    names.insert(MP(names.size(), k));
  }
  
  while(getline(cin, ent)){
    vector<vector<int> > grafo(38), flows(38, vector<int> (38));
    x = ids.find(ent[0])->s;
    sum = f = ent[1] - '0';
    grafo[s].PB(x);
    flows[s][x] = f;
    
    FOR(i, 3, ent.size() - 1){
      y = ids.find(ent[i])->s;
      grafo[x].PB(y);
      flows[x][y] = 1;
      grafo[y].PB(t);
      flows[y][t] = 1;
    }
    
    while(getline(cin, ent)){
      if(ent.size() == 0) break;
      x = ids.find(ent[0])->s;
      f = ent[1] - '0';
      sum += f;
      grafo[s].PB(x);
      flows[s][x] = f;
      
      FOR(i, 3, ent.size() - 1){
        y = ids.find(ent[i])->s;
        grafo[x].PB(y);
        flows[x][y] = 1;
        if(flows[y][t] == 0){
          grafo[y].PB(t);
          flows[y][t] = 1;
        }
      }
    }
    
    if(sum > 10) cout << "!\n";
    else{
      ent = "";
      ft = 0;
      while(true){
        x = bfs(grafo, s, t);
        if(x == INF) break;
        else{
          while(dfs(grafo, flows, s, t, 0, x) != INF){}
        }
      }
      
      if(sum == ft){
        FOR(i, 0, 10){
          k = '0' + i;
          x = ids.find(k)->s;
          if(grafo[x].size() == 0){
            ent += '_';
            continue;
          }
          y = grafo[x][0];
          if(y == t) ent += '_';
          else ent += (char)(y + 'A');
        }
        
        cout << ent << "\n";
      }else cout << "!\n";
    }
  }
  
  return 0;
}