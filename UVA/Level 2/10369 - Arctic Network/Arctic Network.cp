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

bool comp(pair<pair<int, int>, ld> &a, pair<pair<int, int>, ld> &b){
  return a.s < b.s;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return find(p[x], p);
}

void merge(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[b] > s[a]) swap(a, b);
  
  p[b] = a;
  s[a] += b;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(2);
  
  int t, n, x, y, xf, yf, sat, g;
  ld c, epsi = 1e-6, ans;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> sat >> n;
    vector<int> p(n), s(n);
    vector<pair<int, int> > est(n);
    deque<pair<pair<int, int>, ld> > q;
    
    FOR(i, 0, n){
      cin >> x >> y;
      est[i] = MP(x, y);
      p[i] = i;
    }
    
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        x = est[i].f - est[j].f;
        y = est[i].s - est[j].s;
        c = sqrt(x*x + y*y) + epsi;
        q.PB(MP(MP(i, j), c));
      }
    }
    
    sort(q.begin(), q.end(), comp);
    
    g = n;
    ans = 0.0;
    for(int i = 0; i < q.size() and g > sat; i++){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        g--;
        merge(xf, yf, p, s);
        ans = c;
      }
    }
    
    cout << fixed << ans << "\n";
  }

  return 0;
}