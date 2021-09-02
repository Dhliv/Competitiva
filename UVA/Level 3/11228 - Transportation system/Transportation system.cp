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

bool comp(pair<ld, pair<int, int> > &a, pair<ld, pair<int, int> > &b){
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
  int cases, n, x, y, fx, fy, g;
  ld a, b, ans, res, r, epsi = 1e-7;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n >> r;
    vector<int> p(n), s(n, 1);
    FOR(i, 1, n) p[i] = i;
    deque<pair<ld, pair<int, int> > > e, f;
    vector<pair<int, int> > data(n);
    
    FOR(i, 0, n){
      cin >> x >> y;
      data[i] = MP(x, y);
    }
    
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        x = data[i].f - data[j].f;
        y = data[i].s - data[j].s;
        ans = sqrt(x*x + y*y);
        if(ans < r or (fabs(ans - r) < epsi)) e.PB(MP(ans, MP(i, j)));
        else f.PB(MP(ans, MP(i, j)));
      }
    }
    
    sort(e.begin(), e.end(), comp);
    sort(f.begin(), f.end(), comp);
    
    g = n;
    ans = 0.0;
    FOR(i, 0, e.size()){
      x = e[i].s.f;
      y = e[i].s.s;
      fx = find(x, p);
      fy = find(y, p);
      
      if(fx != fy){
        g--;
        ans += e[i].f;
        com(fx, fy, p, s);
      }
    }
    
    res = 0.0;
    FOR(i, 0, f.size()){
      x = f[i].s.f;
      y = f[i].s.s;
      fx = find(x, p);
      fy = find(y, p);
      
      if(fx != fy){
        res += f[i].f;
        com(fx, fy, p, s);
      }
    }
    
    cout << "Case #" << ab + 1 << ": " << g << " " << round(ans) << " " << round(res) << "\n";
  }
  
  return 0;
}