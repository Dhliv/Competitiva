#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_MIN
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  int ops = 0;
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  vector<int> adv;
  FOR(i, 1, 40*40){
    FOR(j, 0, 2) adv.PB(i);
  }

  string s; cin >> s;
  int id = 0;
  vector<vector<int> > p(n, vector<int> (n, INF));

  int r = n/2, c = n/2;
  p[r][c] = id++;

  int dir = 0;
  int changes = 0;
  while(ops < s.size()){
    FOR(i, 0, adv[changes]){
      r += dr[dir];
      c += dc[dir];
      ops++;
      if(ops == s.size()) break;
      p[r][c] = id++;
    }

    changes++;
    dir = (dir + 1)%4;
  }

  FOR(i, 0, n){
    FOR(j, 0, n){
      if(p[i][j] >= s.size()) continue;
      cout << s[p[i][j]];
    }
  }

  cout << "\n";

  return 0;
}