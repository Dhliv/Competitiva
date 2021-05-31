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

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
  return a.s > b.s;
}

int find(int x, vector<int> &p){
  if(p[x] == x) return x;
  return find(p[x], p);
}

void merge(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[b] > s[a]) swap(a, b);
  p[b] = a;
  s[a] += s[b];
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, r, ans, x, y, xf, yf, c, ab = 1;
  string a, b;
  
  while(cin >> n >> r, n + r){
    unordered_map<string, int> id;
    vector<int> s(n, 1), p(n);
    vector<vector<int> > cost(n, vector<int> (n));
    deque<pair<pair<int, int>, int> > q(r);
    FOR(i, 1, n) p[i] = i;
    
    FOR(i, 0, r){
      cin >> a >> b >> c;
      
      if(id.find(a) == id.end()){
        x = id.size();
        id.insert(MP(a, x));
      }else x = id[a];
      
      if(id.find(b) == id.end()){
        y = id.size();
        id.insert(MP(b, y));
      }else y = id[b];
      
      q[i] = MP(MP(x, y), c);
    }
    
    cin >> a >> b;
    sort(q.begin(), q.end(), comp);
    
    FOR(i, 0, r){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        merge(xf, yf, p, s);
        cost[xf][yf] = max(c, cost[xf][yf]);
        cost[yf][xf] = max(c, cost[xf][yf]);
      }
    }
    
    vector<int> seen(n, INF);
    x = id[a];
    xf = x;
    y = id[b];
    ans = INF;
    
    while(x != p[x]){
      ans = min(ans, cost[x][p[x]]);
      seen[p[x]] = ans;
      x = p[x];
    }
    
    ans = INF;
    while(true){
      if(y == xf) break;
      if(seen[y] != INF){
        ans = min(ans, seen[y]);
        break;
      }
      if(y == p[y]) break;
      ans = min(ans, cost[y][p[y]]);
      y = p[y];
    }
    
    cout << "Scenario #" << ab++ << "\n";
    cout << ans << " tons\n\n";
  }

  return 0;
}