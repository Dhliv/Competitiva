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
#define MAX 16

using namespace std;

__int128 p[MAX], xbx, ybx;

bool comp(pair<__int128, int> &a, pair<__int128, int> &b){
  return a.f < b.f;
}

__int128 hs(string &w){
  xbx = 0;
  FOR(i, 0, w.size()){
    ybx = w[i] - 'a' + 1;
    xbx += ybx*p[i];
  }

  return xbx;
}

int look(__int128 &x, deque<pair<__int128, int> > &id){
  int l = 0, h = id.size() - 1, m;

  while(l <= h){
    m = (l + h)/2;
    if(x <= id[m].f) h = m - 1;
    else l = m + 1;
  }

  return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  p[0] = 1;
  FOR(i, 1, MAX) p[i] = p[i - 1]*27;

  int n, c, x, y, ini, dest, t = 0;
  __int128 xb, yb;
  string w, a, b;
  deque<string> name;
  deque<pair<__int128, int> > id;

  while(getline(cin, w)){
    if(w.size() == 0) break;
    xb = hs(w);
    y = name.size();
    name.PB(w);
    id.PB(MP(xb, y));
  }

  sort(id.begin(), id.end(), comp);

  n = id.size();
  vector<vector<int> > g(n);
  vector<int> s(n, INF), f(n, -1);

  FOR(i, 0, n){
    xb = id[i].f;
    x = id[i].s;
    FOR(j, 0, name[x].size()){
      c = name[x][j] - 'a' + 1;

      FOR(k, 1, c){
        yb = xb + (k - c)*p[j];
        y = look(yb, id);
        if(y == n) continue;
        if(yb != id[y].f) continue;
        y = id[y].s;
        g[x].PB(y);
        g[y].PB(x);
      }

      FOR(k, c + 1, 27){
        yb = xb + (k - c)*p[j];
        y = look(yb, id);
        if(y == n) continue;
        if(yb != id[y].f) continue;
        y = id[y].s;
        g[x].PB(y);
        g[y].PB(x);
      }
    }
  }

  deque<int> q;
  while(cin >> a >> b){
    if(t++) cout << "\n";
    xb = hs(a);
    yb = hs(b);
    ini = id[look(xb, id)].s;
    dest = id[look(yb, id)].s;

    q.PB(ini);
    s[ini] = 0;
    while(!q.empty()){
      x = q.F();
      q.P_F();

      FOR(i, 0, g[x].size()){
        y = g[x][i];
        if(s[y] == INF){
          s[y] = s[x] + 1;
          f[y] = x;
          q.PB(y);
        }
      }
    }

    if(s[dest] == INF) cout << "No solution.\n";
    else{
      deque<int> ans;
      x = dest;
      ans.PF(x);

      while(f[x] != -1){
        x = f[x];
        ans.PF(x);
      }

      FOR(i, 0, ans.size()) cout << name[ans[i]] << "\n";
    }

    FOR(i, 0, n){
      f[i] = -1;
      s[i] = INF;
    }
  }

  return 0;
}