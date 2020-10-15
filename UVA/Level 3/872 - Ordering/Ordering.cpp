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

void topo(vector<vector<int> > &grafo, vector<int> dirs, set<int> ori, set<string> &ans, vector<char> &letras, string res){
  string aux;
  int x, y;
  set<int> dest;
  deque<int> bor;
  
  if(ori.size()){
    forit(p, ori){
      dest = ori;
      x = (*p);
      dest.erase(x);
      aux = res;
      if(res.size())
        aux += " ";
      aux += letras[x];
      
      FOR(i, 0, grafo[x].size()){
        y = grafo[x][i];
        dirs[y]--;
        if(dirs[y] == 0){
          dest.insert(y);
          bor.PB(y);
        }
      }
      topo(grafo, dirs, dest, ans, letras, aux);
      
      FOR(i, 0, grafo[x].size()) dirs[grafo[x][i]]++;
      
      dest.insert(x);
    }
  }else ans.insert(res);
}

int main(){
  int cases, x, y;
  cin >> cases;
  string ent;
  bool cyc;
  getline(cin, ent);
  
  FOR(a, 0, cases){
    if(a) cout << "\n";
    getline(cin, ent);
    getline(cin, ent);
    
    vector<char> letras;
    map<char, int> ids;
    
    FOR(i, 0, ent.size()){
      if(!isspace(ent[i])){
        ids.insert(MP(ent[i], letras.size()));
        letras.PB(ent[i]);
      }
    }
    
    vector<vector<int> > grafo(letras.size());
    vector<int> dirs(letras.size());
    
    getline(cin, ent);
    
    FOR(i, 0, ent.size()){
      if(ent[i] == '<'){
        x = ids.find(ent[i - 1])->s;
        y = ids.find(ent[i + 1])->s;
        grafo[x].PB(y);
        dirs[y]++;
        i += 2;
      }
    }
  
    vector<int> vistos(letras.size());
    deque<int> q;
    cyc = false;
    
    FOR(i, 0, letras.size()){
      if(!vistos[i]){
        vector<int> seen(letras.size());
        q.PB(i);
        while(!q.empty()){
          x = q.F();
          q.P_F();
          
          if(seen[x]) continue;
          seen[x] = 1;
          vistos[x] = 1;
          
          FOR(j, 0, grafo[x].size()){
            y = grafo[x][j];
            if(seen[y]) cyc = true;
            else q.PB(y);
          }
        }
        if(cyc) break;
      }
    }
    
    if(!cyc){
      set<int> ori;
      set<string> ans;
      
      FOR(i, 0, letras.size()) if(dirs[i] == 0) ori.insert(i);
      
      topo(grafo, dirs, ori, ans, letras, "");
      
      forit(res, ans) cout << (*res) << "\n";
    }else cout << "NO\n";
  }
  
  return 0;
}
