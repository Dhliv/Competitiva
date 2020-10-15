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

int look(vector<vector<pair<int, int> > > &times, int l, int nodo){
  int low = 0, high = times[nodo].size() - 1, mid;
  
  if(high < 0) return -1;
  
  while(low <= high){
    mid = (low + high)/2;
    
    if(l <= times[nodo][mid].f) high = mid - 1;
    else low = mid + 1;
  }
  
  if(low < times[nodo].size() and times[nodo][low].f == l) return low;
  return -1;
}

int main(){
  int n, m, x, y, k, vecs, pos;
  cin >> n >> m;
  
  vector<vector<pair<int, int> > > grafo(n + 1);
  
  FOR(i, 0, m){
    cin >> x >> y >> k;
    grafo[x].PB(MP(y, k));
    grafo[y].PB(MP(x, k));
  }
  vector<vector<pair<int, int> > > times(n + 1);
  
  FOR(i, 1, n + 1){
    cin >> k;
    FOR(j, 0, k){
      cin >> x;
      times[i].PB(MP(x, 1));
    }
    
    vecs = 1;
    FORI(j, k - 2, 0){
      if(times[i][j].f + 1 == x){
        times[i][j].s += vecs;
        x--;
        vecs++;
      }else{
        vecs = 1;
        x = times[i][j].f;
      }
    }
  }
  
  priority_queue<pair<int, int> > p;
  vector<int> seen(n + 1, INF), vistos(n + 1);
  seen[1] = 0;
  p.push(MP(0, 1));
  
  while(!p.empty()){
    x = p.top().s;
    p.pop();
    
    if(vistos[x]) continue;
    vistos[x] = 1;
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i].f;
      if(vistos[y]) continue;
      
      k = seen[x];
      pos = look(times, k, x);
      k += grafo[x][i].s;
      
      if(pos != -1) k += times[x][pos].s;
      
      if(seen[y] > k){
        seen[y] = k;
        p.push(MP(-k, y));
      }
    }
  }
  
  if(seen[n] == INF) cout << "-1\n";
  else cout << seen[n] << "\n";
  
  return 0;
}