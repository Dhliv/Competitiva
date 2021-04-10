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
  int cases, n, m, a, x, y, c, fx, fy, ans, air;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n >> m >> a;
    vector<int> p(n + 1), s(n + 1, 1);
    FOR(i, 1, n  + 1) p[i] = i;
    
    deque<pair<int, pair<int, int> > > e;
    FOR(i, 0, m){
      cin >> x >> y >> c;
      if(c < a) e.PB(MP(c, MP(x, y)));
    }
    
    sort(e.begin(), e.end(), comp);
    air = n;
    ans = 0;
    FOR(i, 0, e.size()){
      x = e[i].s.f;
      y = e[i].s.s;
      fx = find(x, p);
      fy = find(y, p);
      
      if(fx != fy){
        air--;
        ans += e[i].f;
        com(fx, fy, p, s);
      }
    }
    
    ans += air*a;
    cout << "Case #" << ab + 1 << ": " << ans << " " << air << "\n";
  }
  
  return 0;
}