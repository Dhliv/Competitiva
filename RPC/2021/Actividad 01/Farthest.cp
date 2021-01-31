#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF -1000000000
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int cases, n, m, maxi, xf, yf;
  string ent;
  pair<int, int> x, y, ori;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> m >> n;
    vector<string> d(n);
    FOR(i, 0, n) cin >> d[i];
    
    FOR(i, 0, n){
      FOR(j, 0, m){
        if(d[i][j] == '@'){
          ori = MP(i, j);
          break;
        }
      }
    }
    
    vector<vector<int> > s(n, vector<int> (m, INF));
    vector<vector<pair<int, int> > > dads(n, vector<pair<int, int> > (m, MP(-1, -1)));
    s[ori.f][ori.s] = 0;
    deque<pair<int, int> > q;
    q.PB(ori);
    maxi = 0;
    
    int dy[4] = {0, -1, 1, 0};
    int dx[4] = {1, 0, 0, -1};
    
    while(!q.empty()){
      x = q.F();
      q.P_F();
      
      FOR(i, 0, 4){
        xf = x.f + dx[i];
        yf = x.s + dy[i];
        
        if(xf < 0 or xf == n or yf < 0 or yf == m) continue;
        if(d[xf][yf] == '#') continue;
        
        if(s[xf][yf] == INF){
          s[xf][yf] = s[x.f][x.s] + 1;
          dads[xf][yf] = x;
          q.PB(MP(xf, yf));
          maxi = max(maxi, s[xf][yf]);
        }
      }
    }
    
    deque<string> imp;
    FOR(i, 0, n){
      FOR(j, 0, m){
        if(s[i][j] == maxi){
          ent = "";
          x = MP(i, j);
          while(ent.size() < maxi){
            y = dads[x.f][x.s];
            if(x.f < y.f) ent.PB('U');
            else if(x.f > y.f) ent.PB('D');
            else if(x.s < y.s) ent.PB('L');
            else ent.PB('R');
            swap(x, y);
          }
          reverse(ent.begin(), ent.end());
          imp.PB(ent);
        }
      }
    }
    
    sort(imp.begin(), imp.end());
    cout << "Case " << ab + 1 << ":\n" << imp.size() << " " << maxi << "\n";
    FOR(i, 0, imp.size()){
      cout << imp[i] + "\n";
    }
  }
  
  return 0;
}