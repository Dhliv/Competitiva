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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("diamond.in");
  ofstream cout("diamond.out");

  int n, k, maxi, l, r; cin >> n >> k;
  vector<int> p(n + 1); FOR(i, 0, n) cin >> p[i];
  p[n] = INF;

  sort(p.begin(), p.end());

  maxi = 0;
  l = 0; r = 1;
  vector<int> maxis(n + 1, 1), inmaxis(n + 1, 1);
  while(r <= n){
    if(l >= r){
      maxis[r] = maxi;
      r++;
    }
    else if(p[l] + k >= p[r]){
      maxis[r] = max(maxi, r - l + 1);
      inmaxis[r] = r - l + 1;
      r++;
    }
    else{
      maxi = max(maxi, r - l);
      l++;
    }
  }

  int ans = 0, aux;
  FORI(i, n - 1, 0){
    aux = inmaxis[i];
    if(i - aux >= 0) aux += maxis[i - aux];
    ans = max(ans, aux);
  }

  cout << ans << "\n";
  
  return 0;
}