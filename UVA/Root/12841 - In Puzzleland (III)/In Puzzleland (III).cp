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

int n, m, dest;
bool poss;
deque<int> sol;

void dfs(int x, int vecs, vector<int> &seen, vector<vector<int> > &grafo){
  seen[x] = 1;
  int y, ans = vecs + 1;
  if(ans == n and x == dest){
    poss = true;
    return;
  }
  if(ans == n or (ans < n and x == dest)){
    seen[x] = 0;
    return;
  }
  
  FOR(i, 0, grafo[x].size()){
    y = grafo[x][i];
    if(seen[y]) continue;
    dfs(y, ans, seen, grafo);
    if(poss){
      sol.PF(y);
      break;
    }
  }
  
  seen[x] = 0;
  return;
}

int main(){
  int cases, ori, a, b;
  char k, x, y;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cout << "Case " << ab + 1 << ": ";
    cin >> n >> m;
    vector<vector<int> > grafo(26);
    vector<int> seen(26);
    poss = false;
    sol.clear();
    
    FOR(i, 1, n + 1){
      cin >> k;
      if(i == 1) ori = (k - 'A');
      else if(i == n) dest = (k - 'A');
    }
    
    FOR(i, 0, m){
      cin >> x >> y;
      a = (x - 'A');
      b = (y - 'A');
      grafo[a].PB(b);
      grafo[b].PB(a);
    }
    
    FOR(i, 0, 26) sort(grafo[i].begin(), grafo[i].end());
    
    dfs(ori, 0, seen, grafo);
    
    if(poss){
      cout << (char)(ori + 'A');
      FOR(i, 0, sol.size()) cout << (char)(sol[i] + 'A');
      cout << "\n";
    }
    else cout << "impossible\n";
  }
  
  return 0;
}