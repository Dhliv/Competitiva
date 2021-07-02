#include <bits/stdc++.h>
#define INF 1000000000
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

vector<int> seen;
vector<vector<int> > flows, grf;

int bfs(int &ori, int &dest){
  int n = seen.size(), x, y;
  FOR(i, 0, n) seen[i] = INF;
  seen[ori] = 0;
  deque<int> q;
  q.PB(ori);
  
  while(!q.empty()){
    x = q.F();
    q.P_F();
    
    FOR(i, 0, grf[x].size()){
      y = grf[x][i];
      if(seen[y] == INF){
        seen[y] = seen[x] + 1;
        q.PB(y);
      }
    }
  }
  
  return seen[dest];
}

int dfs(int ori, int &dest, int mini){
  int flow = INF, y;
  
  FOR(i, 0, grf[ori].size()){
    y = grf[ori][i];
    if(y == dest){
      flow = min(mini, flows[ori][y]);
      flows[ori][y] -= flow;
      flows[y][ori] += flow;
      if(flows[ori][y] == 0) grf[ori].erase(grf[ori].begin() + i);
      if(flows[y][ori] == flow) grf[y].PB(ori);
      return flow;
    }else if(seen[ori] + 1 == seen[y]){
      flow = dfs(y, dest, min(mini, flows[ori][y]));
      
      if(flow != INF){
        flows[ori][y] -= flow;
        flows[y][ori] += flow;
        if(flows[ori][y] == 0) grf[ori].erase(grf[ori].begin() + i);
        if(flows[y][ori] == flow) grf[y].PB(ori);
        return flow;
      }
    }
  }
  
  return flow;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, k, a, b, x, y, s, t, nxt, l, r, it, id = 1, nn;
  
  while(cin >> n, n){
    cin >> m;
    vector<int> begins(n), ends(n), dist(50005, m);
    deque<int> bg, ed;
    vector<pair<int, int> > inters;
    vector<pair<pair<int, int>, int> > p(n);
    s = 0;
    
    FOR(i, 0, n){
      cin >> k >> a >> b;
      b--;
      begins[i] = a;
      ends[i] = b;
      p[i] = MP(MP(a, b), k);
    }
    
    sort(begins.begin(), begins.end());
    sort(ends.begin(), ends.end());
    
    ed.PB(ends[0]);
    bg.PB(begins[0]);
    x = bg[0];
    FOR(i, 1, n){
      if(x != begins[i]){
        x = begins[i];
        bg.PB(x);
      }
    }
    
    x = ed[0];
    FOR(i, 1, n){
      if(x != ends[i]){
        x = ends[i];
        ed.PB(x);
      }
    }
    
    nxt = bg[0];
    l = 1;
    r = 0;
    while(l < bg.size() and r < ed.size()){
      while(r < ed.size() and nxt > ed[r]) r++;
      if(bg[l] - 1 <= ed[r]) x = bg[l++] - 1;
      else x = ed[r++];
      inters.PB(MP(nxt, x));
      nxt = x + 1;
    }
    
    while(r < ed.size()){
      while(r < ed.size() and nxt > ed[r]) r++;
      if(r >= ed.size()) break;
      x = ed[r];
      inters.PB(MP(nxt, x));
      nxt = x + 1;
    }
    
    nn = n + inters.size() + 2;
    grf.assign(nn, vector<int> (0));
    flows.assign(nn, vector<int> (nn));
    seen.assign(nn, 0);

    t = nn - 1;
    it = n + 1;
    FOR(i, 0, n){
      grf[s].PB(i + 1);
      flows[s][i + 1] = p[i].s;
      x = p[i].f.f;
      y = p[i].f.s;
      
      FOR(j, 0, inters.size()){
        if(x <= inters[j].f and inters[j].s <= y){
          grf[i + 1].PB(it + j);
          flows[i + 1][it + j] = inters[j].s - inters[j].f + 1;
        }
      }
    }

    FOR(i, 0, inters.size()){
      grf[it + i].PB(t);
      flows[it + i][t] = m*(inters[i].s - inters[i].f + 1);
    }

    while(bfs(s, t) != INF){
      while(dfs(s, t, INF) != INF){}
    }
    cout << "Case " << id++ << ": ";
    if(grf[s].size()) cout << "No\n";
    else{
      cout << "Yes\n";
      vector<vector<int> > ans(n + 1);

      FOR(i, 0, inters.size()){
        a = inters[i].f;
        b = inters[i].s;
        l = a;
        
        FOR(j, 0, grf[it + i].size()){
          y = grf[it + i][j];
          if(y == t) continue;
      
          FOR(v, l, 1 + b){
            dist[v]--;
            flows[it + i][y]--;
            ans[y].PB(v);
            if(flows[it + i][y] == 0){
              l = v + 1;
              if(l > b) l = a;
              break;
            }
          }
          
          if(flows[it + i][y] > 0){
            l = a;
            FOR(v, l, 1 + b){
              dist[v]--;
              flows[it + i][y]--;
              ans[y].PB(v);
              if(flows[it + i][y] == 0){
                l = v + 1;
                if(l > b) l = a;
                break;
              }
            }
          }
        }
      }

      deque<pair<int, int> > imp, sol;
      FOR(i, 1, it){
        x = ans[i][0];
        y = x + 1;
        
        FOR(j, 1, ans[i].size()){
          if(y == ans[i][j]) y = ans[i][j] + 1;
          else{
            imp.PB(MP(x, y));
            x = ans[i][j];
            y = x + 1;
          }
        }

        imp.PB(MP(x, y));
        sort(imp.begin(), imp.end());
        
        x = imp.F().f;
        y = imp.F().s;
        imp.P_F();
        while(!imp.empty()){
          r = imp.F().f;
          if(r == y) y = imp.F().s;
          else{
            sol.PB(MP(x, y));
            x = r;
            y = imp.F().s;
          }
          imp.P_F();
        }
        sol.PB(MP(x, y));
        
        cout << sol.size();
        while(!sol.empty()){
          cout << " (" << sol.F().f << "," << sol.F().s << ")";
          sol.P_F();
        }
        cout << "\n";
      }
    }
  }

  return 0;
}