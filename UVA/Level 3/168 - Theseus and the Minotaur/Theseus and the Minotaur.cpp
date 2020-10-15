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

int ingra(vector<vector<int> > &grafo, int ori, string ent, int pos){
  FOR(i, pos, ent.size()){
    if(0 <= ent[i] - 'A' and ent[i] - 'A' < 26){
      grafo[ori].PB(ent[i] - 'A');
    }else return i - 1;
  }
}

int main(){
  int x, y, tes, mino, k, pos, cont;
  string ent;
  bool able;
  
  while(true){
    getline(cin, ent);
    if(ent == "#") break;
    
    vector<vector<int> > grafo(26);
    
    FOR(i, 0, ent.size()){
      if(0 <= ent[i] - 'A' and ent[i] - 'A' < 26 and ent[i + 1] == ':'){
        i = ingra(grafo, ent[i] - 'A', ent, i + 2);
      }else if(ent[i] == '.'){
        pos = i + 1;
        break;
      }
    }
    
    deque<int> ans;
    
    FOR(i, pos, ent.size()){
      if(0 <= ent[i] - 'A' and ent[i] - 'A' < 26) ans.PB(ent[i] - 'A');
      else if(!isspace(ent[i])) ans.PB(stoi(ent.substr(i, ent.size() - 1)));
    }
    
    mino = ans[0];
    tes = ans[1];
    k = ans[2];
    vector<int> seen(26);
    ans.clear();
    cont = 0;
    
    while(true){
      able = false;
      
      FOR(i, 0, grafo[mino].size()){
        y = grafo[mino][i];
        if(seen[y] == 0 and y != tes){
          able = true;
          tes = mino;
          mino = y;
          break;
        }
      }
      
      if(!able){
        ans.PB(mino);
        break;
      }
      cont++;
      if(cont%k == 0){
        ans.PB(tes);
        seen[tes] = 1;
      }
    }
    
    FOR(i, 0, ans.size() - 1) cout << (char)(ans[i] + 'A') << " ";
    cout << "/" << (char)(ans.B() + 'A') << "\n";
  }
  
  return 0;
}