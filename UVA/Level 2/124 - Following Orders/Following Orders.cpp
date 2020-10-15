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

void topo(vector<vector<int> > &grafo, vector<int> dirs, set<int> ori, set<string> &res, string dp, vector<char> &letras){
  string aux;
  int nodo, y;
  deque<int> q;
  set<int> copia;
  
  if(ori.size()){
    forit(x, ori){
      copia = ori;
      nodo = (*x);
      copia.erase(nodo);
      aux = dp;
      aux += letras[nodo];
      
      FOR(i, 0, grafo[nodo].size()){
        y = grafo[nodo][i];
        dirs[y]--;
        if(dirs[y] == 0){
          q.PB(y);
          copia.insert(y);
        }
      }
      topo(grafo, dirs, copia, res, aux, letras);
      
      FOR(i, 0, grafo[nodo].size()) dirs[grafo[nodo][i]]++;
      
      copia.insert(nodo);
    }
  }else res.insert(dp);
}

int main(){
  string ent;
  int x, y, cont = 0;
  
  while(getline(cin, ent)){
    if(cont++) cout << "\n";
    
    vector<char> letras;
    map<char, int> ids;
    
    FOR(i, 0, ent.size()) if(!isspace(ent[i])){
      ids.insert(MP(ent[i], i/2));
      letras.PB(ent[i]);
    }
    
    vector<vector<int> > grafo(letras.size());
    vector<int> dirs(letras.size());
    getline(cin, ent);
    
    FOR(i, 0, ent.size()){
      if(isspace(ent[i])){
        x = ids.find(ent[i - 1])->s;
        y = ids.find(ent[i + 1])->s;
        grafo[x].PB(y);
        dirs[y]++;
        i += 3;
      }
    }
    
    set<int> ori;
    set<string> res;
    
    FOR(i, 0, letras.size()) if(dirs[i] == 0) ori.insert(i);
    
    topo(grafo, dirs, ori, res, "", letras);
    
    forit(x, res){
      cout << (*x) << "\n";
    }
  }
  
  return 0;
}
