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

vector<int> cy, pos, in, mark, p;
vector<vector<int> > grf, cont;

void dfs(int ori, int &f, int id, bool cycle){
  if(mark[ori]) return;
  
  mark[ori] = 1;
  p[ori] = f;
  cy[ori] = cycle;
  pos[ori] = id;
  cont[f].PB(ori);
  dfs(grf[ori][0], f, id + 1, cycle);
  
  return;
}

void start(int ori){
  int y;
  dfs(ori, ori, 0, 1);
  
  FOR(i, 0, cont[ori].size()){
    y = cont[ori][i];
    in[y]--;
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, qr, x, y, k, ps;
  cin >> n >> qr;
  n++;
  
  cy.resize(n); pos.resize(n); in.resize(n); mark.resize(n); p.resize(n);
  grf.resize(n); cont.resize(n);
  
  FOR(i, 1, n){
    cin >> x;
    grf[i].PB(x);
    in[x]++;
  }
  
  deque<int> q, ori;
  FOR(i, 1, n){
    if(in[i] == 0) q.PB(i);
  }
  
  ori = q;
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    y = grf[x][0];
    in[y]--;
    
    if(in[y] == 0) q.PB(y);
  }
  
  FOR(i, 1, n){
    if(in[i]){
      start(i);
    }
  }
  
  FOR(i, 0, ori.size()){
    x = ori[i];
    if(mark[x]) continue;
    dfs(x, x, 0, 0);
  }
  
  FOR(i, 0, qr){
    cin >> x >> k;
    while(!cy[x] and k >= (cont[p[x]].size() - pos[x])){
      k -= (cont[p[x]].size() - pos[x]);
      x = p[x];
      x = grf[cont[x][cont[x].size() - 1]][0];
    }
    
    cout << cont[p[x]][(k + pos[x])%cont[p[x]].size()] << "\n";
  }

  return 0;
}