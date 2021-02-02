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

int main(){
  ios_base::sync_with_stdio(false);
  int cases, n, m, a;
  long double c, acum, ans;
  cin >> cases;
  
  FOR(ab, 0, cases){
    cin >> n >> m;
    vector<int> p(n);
    a = 0;
    FOR(i, 0, n){
      cin >> p[i];
      a += p[i];
    }
    c = 1.0/(a*1.0);
    
    FOR(i, 0, m){
      acum = 0.0;
      FOR(j, 0, n){
        cin >> a;
        acum += a*c*p[j];
      }
      acum += 1e-7;
      a = ((int) acum)%5;
      ans = (int(acum) - a);
      if(fabs(ans - acum) <= 1e-6) cout << (int) ans << " SAME\n";
      else if(fabs(ans - acum + 1e-6) <= 2.5) cout << (int) ans << " DOWN\n";
      else cout << ((int)ans) + 5 << " UP\n";
    }
    cout << "\n";
  }
  
  return 0;
}