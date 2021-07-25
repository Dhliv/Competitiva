#include <bits/stdc++.h>
#define INF 100000
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
  
  ll n, k, ans, x;
  cin >> n >> k;
  vector<pair<int, int> > p(n);
  
  FOR(i, 0, n){
    cin >> x;
    p[i] = MP(x, i);
  }
  
  sort(p.begin(), p.end());
  ans = k/n;
  x = k%n;
  vector<ll> ad(n, ans);
  
  FOR(i, 0, x) ad[p[i].s]++;
  
  FOR(i, 0, n) cout << ad[i] << "\n";

  return 0;
}