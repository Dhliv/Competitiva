#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
#define ll long long
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

bool comp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
  return a.f < b.f;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void com(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[a] > s[b]) swap(a, b);
  p[a] = b;
  s[b] += s[a];
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, y, fx, fy, ans, g, c;
  string a, b;
  
  while(cin >> n >> m){
    if(n == m and m == 0) break;
    vector<int> p(n), s(n, 1);
    unordered_map<string, int> id;
    FOR(i, 1, n) p[i] = i;
    FOR(i, 0, n){
      cin >> a;
      id.insert(MP(a, i));
    }
    
    deque<pair<int, pair<int, int> > > e;
    FOR(i, 0, m){
      cin >> a >> b >> c;
      x = id[a];
      y = id[b];
      e.PB(MP(c, MP(x, y)));
    }
    cin >> a;
    
    sort(e.begin(), e.end(), comp);
    g = n;
    ans = 0;
    FOR(i, 0, m){
      x = e[i].s.f;
      y = e[i].s.s;
      fx = find(x, p);
      fy = find(y, p);
      
      if(fx != fy){
        ans += e[i].f;
        g--;
        com(fx, fy, p, s);
      }
    }
    
    if(g == 1) cout << ans << endl;
    else cout << "Impossible\n";
  }
  
  return 0;
}