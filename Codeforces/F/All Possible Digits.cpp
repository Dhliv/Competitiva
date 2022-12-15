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
#define PI 3.14159265358979323846

using namespace std;

const ld EPSILON = 0.0000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll a, p, l, r, x, maxi, mini, ans, n;

  while(t--){
    cin >> n >> p;
    set<int> has;
    vector<ll> ele(n), cele;

    FOR(i, 0, n){
      cin >> ele[i];
      has.insert(ele[i]);
    }

    l = ele[n -  1];
    ans = 0;
    bool vuelta = l >= n;
    if(!vuelta){
      FORI(i, l - 1, 0){
        if(has.find(i) == has.end()){
          vuelta = true;
          break;
        }
      }
    }

    if(vuelta){
      ans = p - l;
      ele[n - 1] = 0;
      has.insert(0);
      if(n > 1) ele[n - 2]++;
      else has.insert(1);

      FORI(i, n - 2, 0){
        has.insert(ele[i]);
        if(ele[i]/p and i - 1 >= 0) ele[i - 1]++;
      }

      if(ele[0]/p) has.insert(1);

      FORI(i, l - 1, 0){
        if(has.find(i) == has.end()){
          ans += i;
          break;
        }
      }
    }else{
      FORI(i, p - 1, l){
        if(has.find(i) == has.end()){
          ans = i - l;
          break;
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}