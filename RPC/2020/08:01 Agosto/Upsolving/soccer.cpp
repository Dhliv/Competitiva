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

int n;

bool check(ll A, ll B, ll C, vector<pair<int, int> > &t1, vector<pair<int, int> > &t2, int j1, int j2){
  bool able = true;
  int minx, miny, maxx, maxy;
  ll ans;
  minx = min(t1[j1].f, t1[j2].f);
  miny = min(t1[j1].s, t1[j2].s);
  maxx = max(t1[j1].f, t1[j2].f);
  maxy = max(t1[j1].s, t1[j2].s);
  
  FOR(i, 0, n){
    if(i == j1 or i == j2) continue;
    ans = A*t1[i].f + B*t1[i].s + C;
    if(ans == 0 and t1[i].f >= minx and t1[i].f <= maxx and t1[i].s >= miny and t1[i].s <= maxy){
      able = false;
      break;
    }
  }
  
  FOR(i, 0, n){
    ans = A*t2[i].f + B*t2[i].s + C;
    if(ans == 0 and t2[i].f >= minx and t2[i].f <= maxx and t2[i].s >= miny and t2[i].s <= maxy){
      able = false;
      break;
    }
  }
  
  return able;
}

int main(){
  ll x, y, A, B, C;
  cin >> n;
  
  vector<pair<int, int> > t1(n), t2(n);
  
  FOR(i, 0, n){
    cin >> x >> y;
    t1[i] = MP(x, y);
  }
  
  FOR(i, 0, n){
    cin >> x >> y;
    t2[i] = MP(x, y);
  }
  
  vector<vector<int> > grafo(n);
  
  FOR(i, 0, n){
    FOR(j, i + 1, n){
      A = -(t1[j].s - t1[i].s);
      B = t1[j].f - t1[i].f;
      C = -(t1[i].f*A + t1[i].s*B);
      if(check(A, B, C, t1, t2, i, j)){
        grafo[i].PB(j);
        grafo[j].PB(i);
      }
    }
  }
  
  deque<int> q;
  q.PB(0);
  vector<int> seen(n, INF);
  seen[0] = 0;
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grafo[x].size()){
      y = grafo[x][i];
      if(seen[y] == INF){
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }
  }
  
  if(seen[n - 1] == INF) cout << "-1\n";
  else cout << seen[n - 1] << "\n";
  
  return 0;
}