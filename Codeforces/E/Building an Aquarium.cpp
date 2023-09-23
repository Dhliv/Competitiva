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

ll n, x;
vector<int> p(200005);

bool able(ll m){
  ll sum = 0;
  FOR(i, 0, n) sum += max((ll)0, m - p[i]);
  return sum <= x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll l, r, m;

  while(t--){
    cin >> n >> x;
    FOR(i, 0, n) cin >> p[i];
    l = 1; r = 100000000000;

    while(l <= r){
      m = (l + r)/2;
      if(able(m)) l = m + 1;
      else r = m - 1;
    }

    cout << r << "\n";
  }


  return 0;
}