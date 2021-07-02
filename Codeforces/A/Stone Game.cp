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
  
  int t, n, ans, maxi, mini, pmi, pma, x;
  cin >> t;
  
  FOR(ab, 0, t){
    cin >> n;
    ans = INF;
    maxi = MINF;
    mini = INF;
    
    FOR(i, 0, n){
      cin >> x;
      if(x < mini){
        mini = x;
        pmi = i;
      }
      if(x > maxi){
        maxi = x;
        pma = i;
      }
    }
    
    if(pmi < pma) swap(pmi, pma);
    ans = pma + pmi - pma + 1;
    
    ans = min(ans, pma + n - pmi + 1);
    ans = min(ans, n - pma);
    
    cout << ans << "\n";
  }
  
  return 0;
}