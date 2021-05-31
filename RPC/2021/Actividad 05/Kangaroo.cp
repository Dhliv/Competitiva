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
  
  ll n, a, b, ans, mini, x, y;
  cin >> n;
  vector<int> p(n);
  FOR(i, 0, n) cin >> p[i];
  
  sort(p.begin(), p.end());
  
  mini = LLONG_MAX;
  FOR(i, 0, n){
    a = p[i];
    FOR(j, i + 1, n){
      b = p[j];
      ans = 0;
      FOR(k, 0, n){
        x = a - p[k];
        y = b - p[k];
        ans += min(x*x, y*y);
      }
      mini = min(mini, ans);
    }
  }
  
  cout << mini << "\n";

  return 0;
}