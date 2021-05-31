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

ld ans, epsi = 1e-6, c;

bool comp(pair<pair<int, int>, ld> &a, pair<pair<int, int>, ld> &b){
  return a.s < b.s;
}

int find(int x, vector<int> &p){
  if(x == p[x]) return x;
  return p[x] = find(p[x], p);
}

void merge(int &a, int &b, vector<int> &p, vector<int> &s){
  if(s[b] > s[a]) swap(a, b);
  
  p[b] = a;
  s[a] += s[b];
  return;
}

void connect(vector<int> &p, vector<int> &s, deque<pair<pair<int, int>, ld> > &q){
  int xf, yf, x, y;
  
  FOR(i, 0, q.size()){
    x = q[i].f.f;
    y = q[i].f.s;
    c = q[i].s;
    xf = find(x, p);
    yf = find(y, p);
    
    if(xf != yf){
      merge(xf, yf, p, s);
      ans += c;
    }
  }
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(2);
  
  int n, x, y, r;
  ld c;
  
  while(cin >> n){
    vector<int> p(n + 1), s(n + 1, 1);
    vector<pair<int, int> > bl(n);
    deque<pair<pair<int, int>, ld> > q, qex;
    FOR(i, 1, n + 1){
      p[i] = i;
      cin >> x >> y;
      bl[i - 1] = MP(x, y);
    }
    
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        x = bl[i].f - bl[j].f;
        y = bl[i].s - bl[j].s;
        c = sqrt(x*x + y*y) + epsi;
        q.PB(MP(MP(i + 1, j + 1), c));
      }
    }
    
    cin >> r;
    FOR(i, 0, r){
      cin >> x >> y;
      qex.PB(MP(MP(x, y), 0.0));
    }
    
    sort(q.begin(), q.end(), comp);
    ans = 0.0;
    connect(p, s, qex);
    connect(p, s, q);
    
    cout << fixed << ans << "\n";
  }

  return 0;
}