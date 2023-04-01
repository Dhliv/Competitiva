#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;
 
const ld EPSILON = 0.0000001;

struct edge{
  int x, y;
  deque<pair<int, int> > steps;

  edge(){this->x = -1;}
  edge(int x, int y, deque<pair<int, int> > &steps){
    this->x = x;
    this->y = y;
    this->steps = steps;
  }
};

struct query{
  int t, idx, posx, posy;

  query(int t, int idx){
    this->t = t;
    this->idx = idx;
  }

  query(int t, int posx, int posy){
    this->t = t;
    this->posx = posx;
    this->posy = posy;
  }
};

deque<int> ts;
vector<int> sn;
vector<vector<edge> > g;
int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void addEdge(int x, int y, deque<pair<int, int> > steps){
  g[x][y] = edge(x, y, steps);
}

void dfs(int ori){
  int y;
  sn[ori] = 1;

  FOR(i, 0, k + 1){
    if(g[ori][i].x == -1) continue;
    y = g[ori][i].y;
    if(sn[y]) continue;
    dfs(y);
  }

  ts.PF(ori);
}

deque<pair<int, int> > connect(vector<string> &a, vector<string> &b){
  deque<pair<int, int> > q;
  bool able = true;
  int cnt;
  int x, y;

  FOR(i, 0, n){
    if(!able) break;

    FOR(j, 0, m){
      if(!able) break;

      if(a[i][j] != b[i][j]){
        cnt = 0;
        FOR(l, 0, 4){
          x = i + dx[l];
          y = j + dy[l];

          if(x < 0 or x >= n or y < 0 or y >= m){
            able = false;
            break;
          }

          cnt += a[x][y] - '0';
        }

        if(!able) break;

        if(cnt == 4 and a[i][j] == '0'){
          q.PB(MP(i, j));
          continue;
        }

        if(cnt == 0 and a[i][j] == '1'){
          q.PB(MP(i, j));
          continue;
        }

        able = false;
      }
    }
  }

  if(able){
    if(q.empty()){
      q.PB(MP(INF, INF));
    }

    return q;
  }

  q.PB(MP(-1, -1));
  return q;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  vector<vector<string> > p(k + 1, vector<string> (n));
  vector<int> cp(k + 1);
  vector<vector<int> > copia(k + 1); // Copia[i] contiene los nodos que son copias de i.
  deque<pair<int, int> > qe;
  g.assign(k + 1, vector<edge> (k + 1, edge()));
  sn.assign(k + 1, 0);

  FOR(i, 0, k + 1){
    FOR(j, 0, n) cin >> p[i][j];
  }

  FOR(i, 0, k + 1){
    if(cp[i]) continue;

    FOR(j, 0, k + 1){
      if(i == j or cp[j]) continue;

      qe = connect(p[i], p[j]);
      if(qe.F().f == -1) continue;
      if(qe.F().f == INF){
        cp[j] = 1;
        copia[i].PB(j);
        //cout << j << " is a copy of " << i << "\n";
        continue;
      }

      addEdge(i, j, qe);
    }
  }

  /*FOR(i, 0, k + 1){
    cout << i + 1 << ":";
    FOR(j, 0, k + 1){
      if(g[i][j].x == -1) continue;
      cout << " " << g[i][j].y + 1;
    }

    if(cp[i]) cout << " and is copy";
    cout << "\n";
  }
  cout << endl;
  */

  FOR(i, 0, k + 1){
    if(sn[i] or cp[i]) continue;
    dfs(i);
  }

  deque<int> realOrder;
  FOR(i, 0, ts.size()){
    if(cp[ts[i]]) continue;
    realOrder.PB(ts[i]);
  }

  int ori = realOrder.F();
  cout << ori + 1 << "\n";
  deque<query> ans;
  int y;

  while(!realOrder.empty()){
    ori = realOrder.F(); realOrder.P_F();

    for(const int &y: copia[ori]){
      ans.PB(query(2, y + 1));
    }

    if(realOrder.empty()) break;

    edge &e = g[ori][realOrder.F()];
    for(const auto &step: e.steps){
      ans.PB(query(1, step.f + 1, step.s + 1));
    }

    ans.PB(query(2, realOrder.F() + 1));
  }

  cout << ans.size() << "\n";
  FOR(i, 0, ans.size()){
    if(ans[i].t == 1) cout << 1 << " " << ans[i].posx << " " << ans[i].posy << "\n";
    else cout << 2 << " " << ans[i].idx << "\n";
  }

  return 0;
}