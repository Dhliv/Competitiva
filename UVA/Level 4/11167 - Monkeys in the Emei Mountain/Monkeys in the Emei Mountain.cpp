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
int tl;

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
      if(flows[x][y] == 0) continue;
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
    if(flows[ori][y] == 0) continue;
    if(y == dest){
      flow = min(mini, flows[ori][y]);
      flows[ori][y] -= flow;
      flows[y][ori] += flow;
      tl += flow;
      return flow;
    }else if(seen[ori] + 1 == seen[y]){
      flow = dfs(y, dest, min(mini, flows[ori][y]));
      
      if(flow != INF){
        flows[ori][y] -= flow;
        flows[y][ori] += flow;
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
  
  int n, m, k, a, b, x, y, s, t, nxt, l, r, it, id = 1, nn, xf, yf, nth;
  
  while(cin >> n, n){
    cin >> m;
    vector<int> begins(n), ends(n);
    deque<int> bg, ed;
    vector<pair<int, int> > inters;
    vector<pair<pair<int, int>, int> > p(n);
    s = 0;
    tl = nth = 0;
    
    FOR(i, 0, n){
      cin >> k >> a >> b;
      b--;
      nth += k;
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
    flows.assign(nn, vector<int> (nn, 0));
    seen.assign(nn, 0);

    t = nn - 1;
    it = n + 1;
    FOR(i, 0, n){
      grf[s].PB(i + 1);
      grf[i + 1].PB(s);
      flows[s][i + 1] = p[i].s;
      x = p[i].f.f;
      y = p[i].f.s;
      
      FOR(j, 0, inters.size()){
        if(x <= inters[j].f and inters[j].s <= y){
          grf[i + 1].PB(it + j);
          grf[it + j].PB(i + 1);
          flows[i + 1][it + j] = inters[j].s - inters[j].f + 1;
        }
      }
    }

    FOR(i, 0, inters.size()){
      grf[it + i].PB(t);
      grf[t].PB(it + i);
      flows[it + i][t] = m*(inters[i].s - inters[i].f + 1);
    }

    while(bfs(s, t) != INF){
      while(dfs(s, t, INF) != INF){}
    }

    cout << "Case " << id++ << ": ";
    if(nth != tl) cout << "No\n";
    else{
      cout << "Yes\n";
      deque<pair<int, int> > sol;
      vector<deque<pair<int, int> > > imp(it);

      FOR(i, 0, inters.size()){
        a = inters[i].f;
        b = inters[i].s;
        l = a;
        
        FOR(j, 0, grf[it + i].size()){
          y = grf[it + i][j];
          if(y == t or flows[it + i][y] == 0) continue;
      
          xf = l;
          yf = min(l + flows[it + i][y], b + 1);
          imp[y].PB(MP(xf, yf));
          flows[it + i][y] -= yf - l;
          l = yf;
          if(l > b) l = a;
          if(flows[it + i][y]){
            xf = l;
            yf = min(l + flows[it + i][y], b + 1);
            imp[y].PB(MP(xf, yf));
            flows[it + i][y] -= yf - l;
            l = yf;
            if(l > b) l = a;
          }
        }
      }

      FOR(i, 1, it){
        sort(imp[i].begin(), imp[i].end());

        x = imp[i].F().f;
        y = imp[i].F().s;
        imp[i].P_F();
        while(!imp[i].empty()){
          r = imp[i].F().f;
          if(r == y) y = imp[i].F().s;
          else{
            sol.PB(MP(x, y));
            x = r;
            y = imp[i].F().s;
          }
          imp[i].P_F();
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