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

ld maxi(ld &a, ld &b){
  if(a < b) return b;
  return a;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);

  ll n, a, b, al, bl, t;
  ld ans = MINF, u = 1.0, ax;
  cin >> t;

  FOR(ab, 0, t){
    al = bl = a = b = 0;
    cin >> n;
    al = n;
    vector<int> p(n);
    FOR(i, 0, n){
      cin >> p[i];
      a += p[i];
    }

    sort(p.begin(), p.end());

    a -= p[n - 1];
    b += p[n - 1];
    al--;
    bl++;
    ans = (u*a)/(u*al) + (u*b)/(u*bl);
    FORI(i, n - 2, 1){
      a -= p[i];
      b += p[i];
      al--;
      bl++;
      ax = (u*a)/(u*al) + (u*b)/(u*bl);
      ans = maxi(ans, ax);
    }

    cout << fixed << ans << "\n";
  }
  
  return 0;
}
