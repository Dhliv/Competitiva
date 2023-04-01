#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
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
#define PI 3.14159265358979323846

using namespace std;
 
const ld EPSILON = 0.0000001;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, x, y, ans, v, d, dx, reps;
  int l;
  vector<ll> p(200005);

  FOR(ab, 1, t + 1){
    cin >> n >> x >> y;
    FOR(i, 0, n) cin >> p[i];
    sort(p.begin(), p.begin() + n);

    /*if(ab == 2061){
      cout << ";" << n << ";" << x << ";" << y << ";:----";
      FOR(i, 0, n) cout << p[i] << ";";
      cout << "\n";
      return 0;
    }*/

    ans = 0;
    l = 0;
    bool able = true;
    while(true){
      FOR(i, l, n){
        if(x >= p[i]){
          x++;
          l = i + 1;
          ans++;
        }else break;
      }

      if(x >= y){
        ans -= (x - y);
        break;
      }

      d = n - l;
      dx = l - d;
      if(dx <= 0){
        able = false;
        break;
      }

      if(l < n and y > p[l]){
        reps = (p[l] - x + dx - 1)/dx;
        ans += reps*n;
        x += dx*reps;
      }else{
        reps = (y - x + dx - 1)/dx;
        ans += reps*n;
        x += reps*dx;
        ans -= (x - y);
        break;
      }
    }

    cout << (able ? ans : -1) << "\n";
  }

  return 0;
}