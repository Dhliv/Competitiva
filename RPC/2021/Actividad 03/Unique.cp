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

int main(){
  ios_base::sync_with_stdio(false);
  ll n, last, ans, x, id, y;
  cin >> n;
  
  vector<pair<int, int> > ini(n);
  
  FOR(i, 0, n){
    cin >> x;
    ini[i] = MP(x, i);
  }
  
  sort(ini.begin(), ini.end());
  vector<int> p(n);
  
  id = 0;
  x = ini[0].f;
  FOR(i, 0, n){
    if(x != ini[i].f){
      id++;
      x = ini[i].f;
    }
    p[ini[i].s] = id;
  }
  
  vector<int> pos(id + 1, -1);
  
  last = 0;
  ans = 0;
  FOR(i, 0, n){
    if(pos[p[i]] != -1 and pos[p[i]] >= last){
      x = i - pos[p[i]] - 1;
      y = pos[p[i]] - last + 1;
      ans += (y*(y + 1))/2;
      ans += y*x;
      last = pos[p[i]] + 1;
    }
    pos[p[i]] = i;
  }
  
  y = n - last;
  ans += (y*(y + 1))/2;;
  cout << ans << "\n";
  
  return 0;
}