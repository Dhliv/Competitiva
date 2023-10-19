#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846
 
using namespace std;

const ld EPSILON = 0.0000000001;

struct dt{
  pair<int, int> fat;
  char move;

  dt(){}
  dt(pair<int, int> fat, char move) : move(move), fat(fat) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  char id[4] = {'U', 'R', 'D', 'L'};

  int n, m; cin >> n >> m;
  vector<string> b(n);
  FOR(i, 0, n) cin >> b[i];

  deque<pair<int, int> > mns, A;
  vector<vector<int> > sm(n, vector<int> (m, INF)), sa(n, vector<int> (m, INF));
  vector<vector<dt> > f(n, vector<dt> (m));
  FOR(i, 0, n){
    FOR(j, 0, m){
      if(b[i][j] == '#' or b[i][j] == '.') continue;
      if(b[i][j] == 'M'){
        mns.PB(MP(i, j));
        sm[i][j] = 0;
      }else{
        A.PB(MP(i, j));
        sa[i][j] = 0;
      }
    }
  }

  pair<int, int> p;
  int ni, nj;
  while(!mns.empty()){
    p = mns.F();
    mns.P_F();

    FOR(i, 0, 4){
      ni = p.f + dr[i];
      nj = p.s + dc[i];
      if(ni < 0 or ni >= n or nj < 0 or nj >= m or b[ni][nj] == '#' or sm[ni][nj] != INF) continue;
      sm[ni][nj] = sm[p.f][p.s] + 1;
      mns.PB(MP(ni, nj));
    }
  }

  int w;
  while(!A.empty()){
    p = A.F();
    A.P_F();

    FOR(i, 0, 4){
      ni = p.f + dr[i];
      nj = p.s + dc[i];

      if(ni < 0 or ni >= n or nj < 0 or nj >= m or b[ni][nj] == '#' or sa[ni][nj] != INF) continue;
      w = sa[p.f][p.s] + 1;
      if(w >= sm[ni][nj]) continue;
      sa[ni][nj] = w;
      f[ni][nj] = dt(p, id[i]);
      A.PB(MP(ni, nj));
    }
  }

  bool able = false;
  FOR(i, 0, m){
    if(sa[0][i] != INF){
      able = true;
      p = MP(0, i);
    }else if(sa[n - 1][i] != INF){
      able = true;
      p = MP(n - 1, i);
    }
  }

  if(!able){
    FOR(i, 0, n){
      if(sa[i][0] != INF){
        able = true;
        p = MP(i, 0);
      }else if(sa[i][m - 1] != INF){
        able = true;
        p = MP(i, m - 1);
      }
    }
  }

  if(!able) cout << "NO\n";
  else{
    cout << "YES\n";
    cout << sa[p.f][p.s] << "\n";
    deque<char> ans;
    while(sa[p.f][p.s] != 0){
      ans.PF(f[p.f][p.s].move);
      p = f[p.f][p.s].fat;
    }

    FOR(i, 0, ans.size()) cout << ans[i];
    cout << "\n";
  }

  return 0;
}