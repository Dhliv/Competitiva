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

typedef pair<int, pair<int, int> > p3;

int main(){
  int l, r, c;
  p3 ori, dest, x, y;
  
  while(cin >> l >> r >> c, l + r + c){
    vector<vector<string> > maze(l, vector<string> (r));
    vector<vector<vector<vector<p3> > > > grafo(l, vector<vector<vector<p3> > > (r, vector<vector<p3> > (c)));
    
    FOR(i, 0, l){
      FOR(j, 0, r){
        cin >> maze[i][j];
      }
    }
    
    FOR(i, 0, l){
      FOR(j, 0, r){
        FOR(k, 0, c){
          if(maze[i][j][k] != '#'){
            if(maze[i][j][k] == 'S') ori = MP(i, MP(j, k));
            if(maze[i][j][k] == 'E') dest = MP(i, MP(j, k));
            
            if(i + 1 < l and maze[i + 1][j][k] != '#'){
              grafo[i][j][k].PB(MP(i + 1, MP(j, k)));
              grafo[i + 1][j][k].PB(MP(i, MP(j, k)));
            }
            
            if(j + 1 < r and maze[i][j + 1][k] != '#'){
              grafo[i][j][k].PB(MP(i, MP(j + 1, k)));
              grafo[i][j + 1][k].PB(MP(i, MP(j, k)));
            }
            
            if(k + 1 < c and maze[i][j][k + 1] != '#'){
              grafo[i][j][k].PB(MP(i, MP(j, k + 1)));
              grafo[i][j][k + 1].PB(MP(i, MP(j, k)));
            }
          }
        }
      }
    }
    
    deque<p3> q;
    q.PB(ori);
    vector<vector<vector<int> > > seen(l, vector<vector<int> > (r, vector<int> (c, INF)));
    seen[ori.f][ori.s.f][ori.s.s] = 0;
    
    while(!q.empty() and seen[dest.f][dest.s.f][dest.s.s] == INF){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, grafo[x.f][x.s.f][x.s.s].size()){
        y = grafo[x.f][x.s.f][x.s.s][i];
        if(seen[y.f][y.s.f][y.s.s] == INF){
          seen[y.f][y.s.f][y.s.s] = seen[x.f][x.s.f][x.s.s] + 1;
          q.PB(y);
        }
      }
    }
    
    if(seen[dest.f][dest.s.f][dest.s.s] == INF) cout << "Trapped!\n";
    else cout << "Escaped in " << seen[dest.f][dest.s.f][dest.s.s] << " minute(s).\n";
  }
  
  return 0;
}
