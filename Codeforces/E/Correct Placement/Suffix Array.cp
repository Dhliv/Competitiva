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

int k;

int look(int x, vector<pair<int, pair<int, int> > > &s){
  int l = 0, r = k, m;
  
  while(l <= r){
    m = (l + r)/2;
    
    if(x <= s[m].f) r = m - 1;
    else l = m + 1;
  }
  
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t, n, x, y, m, id, cero = 0;
  cin >> t;
  
  FOR(a, 0, t){
    cin >> n;
    vector<int> ans(n, -1);
    vector<pair<int, pair<int, int> > > s(n);
    vector<pair<int, int> > p(n), pre(n);
    
    FOR(i, 0, n){
      cin >> x >> y;
      if(x > y) swap(x, y);
      p[i] = MP(x, y);
      s[i] = MP(x, MP(y, i));
    }
    
    k = n - 1;
    sort(s.begin(), s.end());
    
    pre[0] = MP(s[0].s.f, s[0].s.s);
    FOR(i, 1, n){
      if(s[i].s.f > pre[i - 1].f){
        pre[i] = MP(pre[i - 1].f, pre[i - 1].s);
      }else pre[i] = MP(s[i].s.f, s[i].s.s);
    }
    
    FOR(i, 0, n){
      x = look(p[i].f, s);
      if(x != -1){
        if(pre[x].f < p[i].s) ans[i] = pre[x].s + 1;
      }
      
      x = look(p[i].s, s);
      if(x != -1){
        if(pre[x].f < p[i].f) ans[i] = pre[x].s + 1;
      }
    }
    
    FOR(i, 0, n) cout << ans[i] << " ";
    cout << "\n";
  }
  
  return 0;
}