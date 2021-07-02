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
#define MAX 1000005

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  vector<bool> pr(MAX);
  vector<vector<ll> > prs(MAX), pos(MAX, vector<ll> (1, -1));
  
  FOR(i, 2, MAX){
    if(!pr[i]){
      for(int j = i; j < MAX; j += i){
        prs[j].PB(i);
        pr[j] = 1;
      }
    }
  }
  
  int n;
  ll x, ans, l, r, lim, s;
  cin >> n;
  
  FOR(i, 0, n){
    cin >> x;
    FOR(j, 0, prs[x].size()) pos[prs[x][j]].PB(i);
  }
  
  ans = 0;
  FOR(i, 2, MAX){
    s = pos[i].size();
    if(s > 1){
      FOR(j, 1, s){
        l = pos[i][j] - pos[i][j - 1] - 1;
        r = n - pos[i][j] - 1;
        ans += (l*r + l + r + 1);
      }
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}