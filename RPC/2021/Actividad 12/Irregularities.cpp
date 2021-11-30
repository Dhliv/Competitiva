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

bool poss(ll &c, vector<pair<ll, ll> > &p, int &pos){
  ll mUsed = 0;

  FOR(i, pos, p.size()){
    mUsed += p[i].s;
    if(mUsed > c*p[i].f) return false;
  }

  return true;
}
  
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, l, r, m, x, y;
  int pos = 0;
  cin >> n;
  vector<ll> p(n);
  vector<pair<ll, ll> > ord(n);

  FOR(i, 0, n) cin >> p[i];
  FOR(i, 0, n){
    cin >> x;
    ord[i] = MP(x, p[i]);
  }

  sort(ord.begin(), ord.end());

  FOR(i, 0, n){
    if(ord[i].f != -1){
      pos = i;
      break;
    }
  }

  l = 0;
  r = 10000000000;
  while(l <= r){
    m = (l + r)/2;
    if(poss(m, ord, pos)) r = m - 1;
    else l = m + 1;
  }

  cout << l << "\n";
  
  return 0;
}