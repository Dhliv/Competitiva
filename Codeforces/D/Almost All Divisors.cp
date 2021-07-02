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
  
  int t, n;
  ll res, to;
  bool able;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    vector<ll> p(n);
    deque<int> ans;
    FOR(i, 0, n) cin >> p[i];
    
    sort(p.begin(), p.end());
    res = p[0]*p[n - 1];
    to = sqrt(res);
    
    if(to*to == res) ans.PB(to);
    else to++;
    FOR(i, 2, to){
      if(res%i == 0){
        ans.PB(i);
        ans.PB(res/i);
      }
    }
    
    sort(ans.begin(), ans.end());
    
    able = true;
    if(p.size() != ans.size()) able = false;
    else{
      FOR(i, 0, n){
        if(p[i] != ans[i]){
          able = false;
          break;
        }
      }
    }
    
    if(able) cout << res << "\n";
    else cout << "-1\n";
  }
  
  return 0;
}