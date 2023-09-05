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

bool able(ll w, vector<ll> &p, ll c) {
  __int128 sum = 0, x, rc = c;
  FOR(i, 0, p.size()){
    x = w*2 + p[i];
    sum += x*x;
  }

  return sum >= rc;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  ll n, c, l, r, m;

  while(t--){
    cin >> n >> c;
    vector<ll> p(n); FOR(i, 0, n) cin >> p[i];


    l = 1; r = 1000000000/2;

    while(l <= r){
      m = (l + r)/2;
      if(able(m, p, c)) r = m - 1;
      else l = m + 1;
    }

    cout << l << "\n";
  }
 
  return 0;
}