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

int n, m;

bool comp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
  return a.f > b.f;
}

void look(int i, int j, vector<vector<int> > &d){
  int x = d[i][j];
  d[i][j] = 0;
  
  if(i > 0 and d[i - 1][j] <= x and d[i - 1][j]) look(i - 1, j, d);
  if(j > 0 and d[i][j - 1] <= x and d[i][j - 1]) look(i, j - 1, d);
  if(j + 1 < m and d[i][j + 1] <= x and d[i][j + 1]) look(i, j + 1, d);
  if(i + 1 < n and d[i + 1][j] <= x and d[i + 1][j]) look(i + 1, j, d);
  
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  int ans, x, y;
  cin >> n >> m;
  
  vector<vector<int> > d(n, vector<int> (m));
  deque<pair<int, pair<int, int> > > s;
  
  FOR(i, 0, n){
    FOR(j, 0, m){
      cin >> d[i][j];
      if(d[i][j] <= 1) d[i][j] = 0;
      else s.PB(MP(d[i][j], MP(i, j)));
    }
  }
  
  sort(s.begin(), s.end(), comp);
  
  ans = 0;
  FOR(i, 0, s.size()){
    x = s[i].s.f;
    y = s[i].s.s;
    if(d[x][y]){
      ans++;
      look(x, y, d);
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}