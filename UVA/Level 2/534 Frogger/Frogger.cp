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
  return p[x] = find(p[x], p);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(3);
  
  int n, x, y, xf, yf, ans, o = 0, f = 1, c, id = 1;
  
  while(cin >> n, n){
    vector<pair<int, int> > pu(n);
    FOR(i, 0, n){
      cin >> x >> y;
      pu[i] = MP(x, y);
    }
    
    vector<int> p(n), maxi(n);
    FOR(i, 1, n) p[i] = i;
    
    deque<pair<pair<int, int>, int> > q;
    FOR(i, 0, n){
      FOR(j, i + 1, n){
        x = pu[i].f - pu[j].f;
        y = pu[i].s - pu[j].s;
        q.PB(MP(MP(i, j), x*x + y*y));
      }
    }
    
    sort(q.begin(), q.end(), comp);
    for(int i = 0; i < q.size() and find(o, p) != find(f, p); i++){
      x = q[i].f.f;
      y = q[i].f.s;
      c = q[i].s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        p[yf] = xf;
        maxi[xf] = max(c, max(maxi[xf], maxi[yf]));
      }
    }
    
    cout << "Scenario #" << id++ << "\nFrog Distance = ";
    cout << fixed << sqrt(maxi[find(o, p)]) << "\n\n";
  }
  
  return 0;
}