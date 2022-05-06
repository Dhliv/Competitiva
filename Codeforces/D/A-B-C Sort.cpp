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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int t, n; cin >> t;
  bool able;
 
  FOR(ab, 0, t){
    cin >> n;
    able = true;
    vector<int> p(n), ps(n);
    FOR(i, 0, n){
      cin >> ps[i];
      p[i] = ps[i];
    }
 
    sort(ps.begin(), ps.end());
 
    FOR(i, 0, n){
      if((n - i) & 1) {
        if(ps[i] != p[i]){
          able = false;
          break;
        }
      }else{
 
        if(ps[i] == p[i]) continue;
        if(ps[i] == p[i + 1] and ps[i + 1] == p[i]){
          i++;
          continue;
        }
        able = false;
        break;
      }
    }
 
    cout << (able ? "YES" : "NO") << "\n";
  }
  
  return 0;
}