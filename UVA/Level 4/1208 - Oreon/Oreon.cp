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
  
  int t, n, x, y, c, xf, yf;
  string b;
  cin >> t;
  
  FOR(a, 0, t){
    cout << "Case " << a + 1 << ":\n";
    cin >> n;
    
    vector<int> p(n), s(n);
    deque<pair<pair<int, int>, int> > q, ans;
    
    FOR(i, 1, n) p[i] = i;
    
    FOR(i, 0, n){
      FOR(j, 0, n){
        cin >> b;
        if(j + 1 < n) b = b.substr(0, b.size() - 1);
        if(b != "0") q.PB(MP(MP(i, j), stoi(b)));
      }
    }
    
    sort(q.begin(), q.end(), comp);
    
    FOR(i, 0, q.size()){
      x = q[i].f.f;
      y = q[i].f.s;
      xf = find(x, p);
      yf = find(y, p);
      
      if(xf != yf){
        if(s[yf] > s[xf]) swap(xf, yf);
        p[yf] = xf;
        s[xf] += s[yf];
        ans.PB(q[i]);
      }
    }
    
    FOR(i, 0, ans.size()){
      x = ans[i].f.f;
      y = ans[i].f.s;
      c = ans[i].s;
      if(x > y) swap(x, y);
      
      cout << (char)(x + 'A') << "-" << (char)(y + 'A') << " " << c << "\n";
    }
  }

  return 0;
}