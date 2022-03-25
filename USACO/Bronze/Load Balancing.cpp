#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
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

int f(int x, int y, vector<pair<int, int> > &p){
  int ans[2][2] = {0}, s1, s2;

  FOR(i, 0, p.size()){
    s1 = p[i].f < x ? 0 : 1;
    s2 = p[i].s < y ? 0 : 1;
    ans[s1][s2]++;
  }

  int maxi = 0;
  FOR(i, 0, 2){
    FOR(j, 0, 2) maxi = max(maxi, ans[i][j]);
  }

  return maxi;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("balancing.in");
  ofstream cout("balancing.out");

  int n, b; cin >> n >> b;
  int mini = INF;
  vector<pair<int, int> > p(n);

  FOR(i, 0, n) cin >> p[i].f >> p[i].s;

  FOR(i, 0, n){
    FOR(j, 0, n){
      mini = min(mini, f(p[i].f + 1, p[j].s + 1, p));
      mini = min(mini, f(p[i].f + 1, p[j].s - 1, p));
      mini = min(mini, f(p[i].f - 1, p[j].s + 1, p));
      mini = min(mini, f(p[i].f - 1, p[j].s - 1, p));

    }
  }

  cout << mini << "\n";

  return 0;
}
