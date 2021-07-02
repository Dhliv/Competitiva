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
  cin.tie(NULL);
  cout.tie(NULL);
  
  int p = 1e9 + 7, t, n, ax, pos, p2 = 1e9 + 9, mini;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    vector<int> d(n);
    deque<pair<int, pair<int, int> > > ans;
    
    pos = INF;
    FOR(i, 0, n){
      cin >> d[i];
      if(i){
        ax = __gcd(d[i], d[i - 1]);
        if(ax != 1){
          mini = min(d[i], d[i - 1]);
          if(pos == i - 2){
            ans.PB(MP(i + 1, MP(p2, mini)));
          }else{
            ans.PB(MP(i + 1, MP(p, mini)));
            pos = i - 1;
          }
          d[i] = mini;
        }
      }
    }
    
    cout << ans.size() << "\n";
    FOR(i, 0, ans.size()){
      ax = ans[i].f;
      cout << ax - 1 << " " << ax << " " << ans[i].s.f << " " << ans[i].s.s << "\n";
    }
  }
  
  return 0;
}