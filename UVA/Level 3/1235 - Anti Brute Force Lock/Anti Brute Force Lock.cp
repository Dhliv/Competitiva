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
  if(s[b] > s[a]) swap(a, b);
  p[a] = b;
  s[b] += s[a];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases, n, x, y, fx, fy, ans, mini;
  string a, o = "0000", b;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n;
    deque<string> q(n + 1);
    vector<int> p(n + 1), s(n + 1, 1);
    FOR(i, 1, n + 1) p[i] = i;
    q[0] = o;
    mini = INF;
    FOR(i, 1, n + 1) cin >> q[i];
    
    deque<pair<int, pair<int, int> > > e;
    FOR(i, 0, n + 1){
      a = q[i];
      FOR(j, i + 1, n + 1){
        ans = 0;
        b = q[j];
        FOR(k, 0, a.size()){
          x = a[k] - '0';
          y = b[k] - '0';
          if(x > y) swap(x, y);
          ans += min(y - x, x + 10 - y);
        }
        if(i != 0) e.PB(MP(ans, MP(i, j)));
        else{
          mini = min(mini, ans);
        }
      }
    }
    
    sort(e.begin(), e.end(), comp);
    ans = 0;
    FOR(i, 0, e.size()){
      x = e[i].s.f;
      y = e[i].s.s;
      fx = find(x, p);
      fy = find(y, p);
      
      if(fx != fy){
        ans += e[i].f;
        com(fx, fy, p, s);
      }
    }
    
    cout << ans + mini << "\n";
  }
  
  return 0;
}