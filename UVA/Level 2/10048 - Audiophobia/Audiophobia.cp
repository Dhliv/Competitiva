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
  return a.s <= b.s;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
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
  
  int n, r, q, ans, x, y, xf, yf, c, id, ab = 0;
  
  while(cin >> n >> r >> q, n){
    if(ab++) cout << "\n";
    n++;
    vector<int> p(n), s(n, 1), seen(n, MINF), v(n, -1);
    vector<pair<pair<int, int>, int> > ed(r);
    vector<vector<int> > cost(n, vector<int> (n));
    FOR(i, 1, n) p[i] = i;
    
    FOR(i, 0, r){
      cin >> x >> y >> c;
      ed[i] = MP(MP(x, y), c);
    }
    
    sort(ed.begin(), ed.end(), comp);
    
    FOR(i, 0, r){
      x = ed[i].f.f;
      y = ed[i].f.s;
      c = ed[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        merge(xf, yf, p, s);
        cost[xf][yf] = c;
        cost[yf][xf] = c;
      }
    }
    
    cout << "Case #" << ab << "\n";
    id = 0;
    FOR(i, 0, q){
      cin >> x >> y;
      xf = x;
      
      if(find(x, p) == find(y, p)){
        ans = MINF;
        while(x != p[x]){
          ans = max(ans, cost[x][p[x]]);
          seen[p[x]] = ans;
          v[p[x]] = id;
          x = p[x];
        }
        
        ans = MINF;
        while(true){
          if(y == xf) break;
          if(v[y] == id){
            ans = max(ans, seen[y]);
            break;
          }
          if(y == p[y]) break;
          ans = max(ans, cost[y][p[y]]);
          y = p[y];
        }
        
        cout << ans << "\n";
      }else cout << "no path\n";
      
      id++;
    }
  }

  return 0;
}