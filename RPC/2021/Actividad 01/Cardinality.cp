#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ld long double
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
  int n, m, rep, nr, a, pos;
  bool able;
  
  while(cin >> n >> m){
    if(n == m and m == 0) break;
    deque<int> p(n);
    FOR(i, 0, n) cin >> p[i];
    sort(p.begin(), p.end());
    
    rep = nr = 0;
    FOR(i, 0, m){
      cin >> a;
      pos = lower_bound(p.begin(), p.end(), a) - p.begin();
      if(pos == n) nr++;
      else if(p[pos] != a) nr++;
      else rep++;
    }
    
    cout << n - rep << " " << rep << " " << m - rep << " " << n + nr << "\n";
  }
  
  return 0;
}