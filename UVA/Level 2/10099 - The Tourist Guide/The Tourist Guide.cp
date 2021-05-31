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
  if(x == p[x]) return x;
  return find(p[x], p);
}

void merge(int &a, int &b, int &c, vector<int> &p, vector<int> &s, vector<int> &cost){
  if(s[b] > s[a]) swap(a, b);
  
  p[b] = a;
  s[a] += s[b];
  cost[b] = c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, r, x, y, c, xf, yf, ans, ab = 1, a, b, pa, res;
  
  while(cin >> n >> r, n){
    cout << "Scenario #" << ab++ << "\nMinimum Number of Trips = ";
    n++;
    vector<int> p(n), s(n, 1), seen(n, INF), cost(n);
    vector<pair<pair<int, int>, int> > q(r);
    FOR(i, 1, n) p[i] = i;
    
    FOR(i, 0, r){
      cin >> x >> y >> c;
      q[i] = MP(MP(x, y), c);
    }
    
    sort(q.begin(), q.end(), comp);
    cin >> a >> b >> pa;
    
    FOR(i, 0, r){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf) merge(xf, yf, c, p, s, cost);
    }
    
    x = a;
    ans = INF;
    while(x != p[x]){
      ans = min(ans, cost[x]);
      seen[p[x]] = ans;
      x = p[x];
    }
    
    y = b;
    ans = INF;
    while(true){
      if(y == a) break;
      if(seen[y] != INF){
        ans = min(ans, seen[y]);
        break;
      }
      if(y == p[y]) break;
      ans = min(ans, cost[y]);
      y = p[y];
    }
    
    cout << (pa/(ans - 1) + ((pa%(ans - 1) > 0) ? 1 : 0)) << "\n\n";
  }

  return 0;
}