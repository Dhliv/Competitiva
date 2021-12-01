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

ll mini(ll &a, ll b){
  if(a < b) return a;
  return b;
}

bool poss(ll &k, ll &h, vector<ll> &p){
  ll acum = k;

  FOR(i, 1, p.size()){
    acum += mini(k, p[i] - p[i - 1]);
  }

  return (acum >= h);
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, t;
  ll h, l, r, m;

  cin >> t;

  FOR(ab, 0, t){
    cin >> n >> h;
    vector<ll> p(n);
    FOR(i, 0, n) cin >> p[i];

    l = 1;
    r = h;
    while(l <= r){
      m = (l + r)/2;

      if(poss(m, h, p)) r = m - 1;
      else l = m + 1;
    }

    cout << l << "\n";
  }
  
  return 0;
}