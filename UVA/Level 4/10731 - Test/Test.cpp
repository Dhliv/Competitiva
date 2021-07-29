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

vector<vector<int> > g[2];
deque<int> ts;
vector<bool> v;
deque<deque<int> > ans;
int tag;

void dfs(int &id, int x){
  v[x] = 1;

  FOR(y, 0, 26){
    if(g[id][x][y] and !v[y]) dfs(id, y);
  }

  if(id == 0) ts.PF(x);
  else ans[tag].PB(x);
}

bool comp(deque<int> &a, deque<int> &b){
  return a.F() < b.F();
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y, z = 0, u = 1, id = 0;
  char a, b;

  while(cin >> n, n){
    if(id++) cout << "\n";
    g[0].assign(26, vector<int> (26, 0));
    g[1].assign(26, vector<int> (26, 0));
    v.assign(26, 0);
    vector<bool> s(26);

    vector<int> p(5);
    FOR(i, 0, n){
      FOR(j, 0, 5){
        cin >> a;
        p[j] = a - 'A';
        s[p[j]] = 1;
      }
      cin >> b;
      x = b - 'A';
      FOR(j, 0, 5){
        if(x == p[j]) continue;
        g[0][x][p[j]] = 1;
        g[1][p[j]][x] = 1;
      }
    }

    FOR(i, 0, 26){
      if(!v[i] and s[i]) dfs(z, i);
    }
  
    FOR(i, 0, 26) v[i] = 0;

    deque<int> vacio;
    tag = 0;
    while(!ts.empty()){
      x = ts.F();
      ts.P_F();

      if(!v[x]){
        ans.PB(vacio);
        dfs(u, x);
        tag++;
      }
    }

    FOR(i, 0, ans.size()) sort(ans[i].begin(), ans[i].end());

    sort(ans.begin(), ans.end(), comp);

    while(!ans.empty()){
      cout << (char) (ans.F().F() + 'A');
      FOR(i, 1, ans[0].size()) cout << " " << (char) (ans[0][i] + 'A');
      cout << "\n";
      ans.P_F();
    }
  }

  return 0;
}
