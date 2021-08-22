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

  int t, n, a, b, ans, x, u, z, cn, y, maxi;
  string s;
  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> a >> b;
    cin >> s;
    u = z = 0;
    deque<int> us, zs;

    if(b >= 0) cout << n*(a + b) << "\n";
    else{
      x = s[0] - '0';
      cn = 1;
      s.PB('2');
      FOR(i, 1, s.size()){
        y = s[i] - '0';
        if(x != y){
          if(x == 1){
            us.PB(cn);
            u++;
          }else{
            zs.PB(cn);
            z++;
          }
          cn = 0;
          x = y;
        }
        cn++;
      }

      ans = 0;
      if(z > u){
        FOR(i, 0, us.size()) ans += (us[i]*a + b);
        z = 0;
        FOR(i, 0, zs.size()) z += zs[i];
        ans += z*a + b;
      }else if(z < u){
        FOR(i, 0, zs.size()) ans += (zs[i]*a + b);
        u = 0;
        FOR(i, 0, us.size()) u += us[i];
        ans += u*a + b;
      }else{
        z = 0;
        FOR(i, 0, zs.size()) z += zs[i];
        u = 0;
        FOR(i, 0, us.size()) u += us[i];
        FOR(i, 0, us.size()) ans += (us[i]*a + b);
        ans += z*a + b;

        maxi = ans;
        ans = 0;
        FOR(i, 0, zs.size()) ans += (zs[i]*a + b);
        ans += u*a + b;

        ans = max(ans, maxi);
      }

      cout << ans << "\n";
    }
  }

  return 0;
}