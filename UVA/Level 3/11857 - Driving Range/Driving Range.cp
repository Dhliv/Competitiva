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
  return a.s < b.s;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return p[x];
  return p[x] = find(p[x], p);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m, x, y, c, xf, yf, ans, g;
  
  while(cin >> n >> m, n + m){
    deque<pair<pair<int, int>, int> > q;
    vector<int> p(n), s(n);
    
    FOR(i, 0, m){
      cin >> x >> y >> c;
      q.PB(MP(MP(x, y), c));
    }
    
    FOR(i, 1, n) p[i] = i;
    
    sort(q.begin(), q.end(), comp);
    
    ans = 0;
    g = n;
    FOR(i, 0, m){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        if(s[yf] > s[xf]) swap(xf, yf);
        p[yf] = xf;
        s[xf] += s[yf];
        g--;
        ans = max(ans, c);
      }
    }
    
    if(g == 1) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";
  }

  return 0;
}