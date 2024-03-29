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
  
  int n, t, x;
  ll ans, mini;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    vector<int> p(2*n + 10), d(n);
    
    mini = INF;
    FOR(i, 0, n){
      cin >> d[i];
      mini = min(mini, d[i] - i);
    }
    
    if(mini < 0) mini = abs(mini);
    else mini = 0;
    
    FOR(i, 0, n){
      x = mini + d[i] - i;
      p[x]++;
    }
    
    ans = 0;
    FOR(i, 0, n - 1){
      x = mini + d[i] - i;
      ans += (p[x] - 1);
      p[x]--;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}