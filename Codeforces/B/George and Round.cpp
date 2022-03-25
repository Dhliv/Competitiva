#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
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

  int n, m, l, r, ans; cin >> n >> m;
  vector<int> a(n), b(m);

  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, m) cin >> b[i];

  l = n - 1;
  r = m - 1;
  ans = 0;

  while(l >= 0 and r >= 0){
    if(b[r] < a[l]) ans++;
    else r--;
    l--;
  }

  cout << (ans + l + 1) << "\n";
  
  return 0;
}
