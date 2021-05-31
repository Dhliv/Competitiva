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
  
  int t, n, r, x, y, xf, yf, ans, c, mini;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n >> r;
    n++;
    vector<int> p(n), s(n, 1);
    deque<pair<pair<int, int>, int> > q(r), us, nus;
    FOR(i, 1, n) p[i] = i;
    
    FOR(i, 0, r){
      cin >> x >> y >> c;
      q[i] = MP(MP(x, y), c);
    }
    
    sort(q.begin(), q.end(), comp);
    
    ans = 0;
    FOR(i, 0, r){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        merge(xf, yf, p, s);
        us.PB(MP(MP(xf, yf), c));
        ans += c;
      }else nus.PB(q[i]);
    }
    
    mini = INF;
    FOR(i, 0, us.size()){
      x = us[i].f.f;
      y = us[i].f.s;
      c = us[i].s;
      p[y] = y;
      
      FOR(j, 0, nus.size()){
        xf = find(nus[j].f.f, p);
        yf = find(nus[j].f.s, p);
        
        if(xf != yf){
          mini = min(mini, ans - c + nus[j].s);
          break;
        }
      }
      
      p[y] = x;
    }
    
    cout << ans << " " << mini << "\n";
  }

  return 0;
}