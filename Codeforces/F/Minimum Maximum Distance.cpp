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
 
const ld EPSILON = 0.000000001;

int farNodeMark(int ini, vector<vector<int> > &g, vector<int> &mark){
  vector<int> s(g.size(), INF);
  deque<int> q(1, ini);
  s[ini] = 0;
  int x;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y : g[x]){
      if(s[y] != INF) continue;
      s[y] = s[x] + 1;
      q.PB(y);
    }
  }

  int maxi = 0;
  int pos = -1;

  FOR(i, 0, g.size()){
    if(mark[i] == 0) continue;
    if(s[i] <= maxi) continue;
    maxi = s[i];
    pos = i;
  }

  return pos;
}

void bfs(int ini, vector<int> &s, vector<vector<int> > &g){
  deque<int> q(1, ini);
  s[ini] = 0;
  int x;

  while(!q.empty()){
    x = q.F();
    q.P_F();

    for(const int &y : g[x]){
      if(s[y] != INF) continue;
      s[y] = s[x] + 1;
      q.PB(y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  int n, k, m, x, y, lastm;

  while(t--){
    cin >> n >> k;
    vector<vector<int> > g(n);
    vector<int> mark(n);

    FOR(i, 0, k){
      cin >> x;
      x--;
      mark[x] = 1;
      lastm = x;
    }

    FOR(i, 0, n - 1){
      cin >> x >> y;
      x--; y--;
      g[x].PB(y);
      g[y].PB(x);
    }

    int a = lastm, b = -1;
    if(k > 1){
      a = farNodeMark(lastm, g, mark);
      b = farNodeMark(a, g, mark);
    }

    vector<int> s1(n, INF), s2(n, INF);
    bfs(a, s1, g);
    if(b != -1) bfs(b, s2, g);

    int mini = INF, val;
    FOR(i, 0, n){
      val = s1[i];
      if(b != -1) val = max(val, s2[i]);
      mini = min(mini, val);
    }

    cout << mini << "\n";
  }

  return 0;
}