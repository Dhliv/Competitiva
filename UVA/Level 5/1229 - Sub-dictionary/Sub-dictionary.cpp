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

vector<vector<int> > g[2], gr;
vector<bool> v, add;
deque<int> ts, aans;
int tag;

string nxtw(string &a, int &pos){
  string b = "";
  FOR(i, pos, a.size()){
    if(isspace(a[i])){
      pos = i + 1;
      break;
    }
    b.PB(a[i]);
  }

  return b;
}

void dfs(int &id, int x){
  v[x] = 1;

  for(int y: g[id%2][x]){
    if(!v[y]) dfs(id, y);
  }

  if(id == 0) ts.PF(x);
  else if(id == 1) gr[tag].PB(x);
  else if(id == 2 and !add[x]){
    aans.PB(x);
    add[x] = 1;
  }
  return;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y, pos, z = 0, u = 1, d = 2;
  string a, b, c;

  while(cin >> n, n){
    getline(cin, a);
    map<string, int> id;
    vector<string> name(n);

    v.assign(n, 0);
    g[0].assign(n, {});
    g[1].assign(n, {});

    FOR(i, 0, n){
      getline(cin, a);
      a.PB(' ');
      pos = 0;
      b = nxtw(a, pos);

      if(id.find(b) == id.end()){
        x = id.size();
        name[x] = b;
        id.insert(MP(b, x));
      }else x = id[b];

      while(pos < a.size()){
        c = nxtw(a, pos);

        if(id.find(c) == id.end()){
          y = id.size();
          name[y] = c;
          id.insert(MP(c, y));
        }else y = id[c];

        g[0][x].PB(y);
        g[1][y].PB(x);
      }
    }

    FOR(i, 0, n){
      if(!v[i]) dfs(z, i);
    }

    FOR(i, 0, n) v[i] = 0;

    tag = 0;
    gr.assign(n, {});

    while(!ts.empty()){
      x = ts.F();
      ts.P_F();

      if(!v[x]){
        dfs(u, x);
        tag++;
      }
    }

    FOR(i, 0, n) v[i] = 0;

    add.assign(n, 0);
    deque<string> ans;
    FOR(i, 0, tag){
      if(gr[i].size() > 1){
        dfs(d, gr[i][0]);
      }
    }

    while(!aans.empty()){
      x = aans.F();
      aans.P_F();
      ans.PB(name[x]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    cout << ans.F();
    FOR(i, 1, ans.size()) cout << " " << ans[i];
    cout << "\n";
  }

  return 0;
}
